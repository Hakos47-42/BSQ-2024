/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:06:29 by pabmart2          #+#    #+#             */
/*   Updated: 2024/07/09 16:58:14 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "bsq.h"

/*
	Checks if the 'obstacle' char is present in up and left directions
	until reaching 'diagonal_size' setps.

	Return 0 --> No obstacle found
	Return 1 --> Obstacle found
*/
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

/*
	Iterates diagonally from a 'origin', going +1 in each dimension every step until
	reaching 'size'.
*/
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

/*
	It takes the square, the possible new dimension and
	the coordinates of the new square to update it
	in case the new one is bigger than the previous.
*/
void	update_square(t_square square, unsigned int tmp_dimension,
		unsigned int origin_yx[])
{
	if (tmp_dimension > square->dimension)
	{
		square->dimension = tmp_dimension;
		square->x = origin_yx[1];
		square->y = origin_yx[0];
	}
}

/*
	Main algorithm function. It will iterate all the points from the
	matrix and find the biggest square possible, returning it.
*/
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
				update_square(square, tmp_dimension, count_yx);
			}
			count_yx[1]++;
		}
		count_yx[0]++;
	}
	return (square);
}
