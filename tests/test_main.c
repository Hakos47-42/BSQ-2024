/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:25:58 by pabmart2          #+#    #+#             */
/*   Updated: 2024/07/09 16:35:14 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct					s_square
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		dimension;
};

typedef struct s_square	*t_square;

int	check_obstacles(char **matrix, char symbols[], unsigned int coords[],
		unsigned int diagonal_size)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;

	y = coords[0];
	x = coords[1];
	i = 0;
	while (i <= diagonal_size)
	{
		if (matrix[y][x] == symbols[1])
			return (1);
		--x;
		++i;
	}
	i = 0;
	x = coords[1];
	while (i <= diagonal_size)
	{
		if (matrix[y][x] == symbols[1])
			return (1);
		--y;
		++i;
	}
	return (0);
}

int	diagonal_check(char **matrix, char symbols[], unsigned int origin[],
		unsigned int size[])
{
	int				iterating;
	unsigned int	diagonal_size;
	unsigned int	coords[2];

	coords[0] = origin[0];
	coords[1] = origin[1];
	iterating = 0;
	diagonal_size = 0;
	while (iterating == 0 && coords[0] < size[0] && coords[1] < size[1])
	{
		iterating = check_obstacles(matrix, symbols, coords, diagonal_size);
		coords[0]++;
		coords[1]++;
		if (iterating == 0)
			diagonal_size++;
	}
	return (diagonal_size);
}

t_square	matrix_iterator(char **matrix, char symbols[], unsigned int size[])
{
	unsigned int	count_yx[2];
	unsigned int	tmp_dimension;
	t_square		square;

	square = (t_square)malloc(3 * sizeof(int));
	square->dimension = 0;
	count_yx[0] = 0;
	count_yx[1] = 0;
	while (count_yx[0] < size[0])
	{
		while (count_yx[1] < size[1])
		{
			if (matrix[count_yx[0]][count_yx[1]] == symbols[0])
			{
				tmp_dimension = diagonal_check(matrix, symbols, count_yx, size);
				if (tmp_dimension > square->dimension)
				{
					square->dimension = tmp_dimension;
					square->x = count_yx[1];
					square->y = count_yx[0];
				}
			}
			count_yx[1]++;
		}
		count_yx[0]++;
	}
	return (square);
}

void	fill_matrix(char **matrix, char fill_symbol, t_square square)
{
	unsigned int	i;
	unsigned int	j;

	i = square->y;
	j = square->x;
	while (i < square->y + square->dimension)
	{
		while (j < square->x + square->dimension)
		{
			matrix[i][j] = fill_symbol;
			++j;
		}
		j = square->x;
		++i;
	}
}

void	debug_print_matrix(char **matrix, unsigned int size[])
{
	unsigned int	i;

	i = 0;
	while (i < size[0])
	{
		printf("%s \n", matrix[i]);
		++i;
	}
}

int	main(void)
{
	char			line1[] = "--o-----";
	char			line2[] = "--o---oo";
	char			line3[] = "ooo--o--";
	char			line4[] = "-----o--";
	char			*matrix[] = {line1, line2, line3, line4};
	unsigned int	size[2] = {4, 8};

	printf("Empezando iteración \n");
	fill_matrix(matrix, 'X', matrix_iterator(matrix, "-o", size));
	debug_print_matrix(matrix, size);
}
