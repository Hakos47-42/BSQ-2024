/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:26:31 by varias-c          #+#    #+#             */
/*   Updated: 2024/07/10 20:27:04 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "file_options.h"

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

int	main(int argc, char *argv[])
{
	t_file_options	map_options;
	t_square		s;
	char			symbols[3];
	int				i;

	if (argc != 2)
		ft_error("Arguments invalid");
	map_options = validate_map(argv[1]);
	i = -1;
	while (++i < 3)
		symbols[i] = map_options.chars[i];
	s = matrix_iterator(map_options.map, symbols, map_options.y_x);
	fill_matrix(map_options.map, symbols[2], s);
	ft_print_map(map_options.map, map_options.y_x);
	free(map_options.map);
	return (0);
}
