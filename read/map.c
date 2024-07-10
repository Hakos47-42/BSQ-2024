/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:26:17 by varias-c          #+#    #+#             */
/*   Updated: 2024/07/10 20:26:17 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_map(char **map, unsigned int *y_x)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	while (i < y_x[0])
	{
		while (j < y_x[1])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

char	**asigned_map(char **map, char *buffer)
{
	int	i;
	int	lines;
	int	col;

	i = 0;
	lines = 0;
	col = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i])
	{
		if (buffer[i] != '\n')
		{
			map[lines][col] = buffer[i];
			col++;
		}
		else if (buffer[i] == '\n')
		{
			lines++;
			col = 0;
		}
		i++;
	}
	return (map);
}

char	**create_map(char *buffer, unsigned int *args_y_x)
{
	char	**map;
	int		lines;
	int		i;

	i = 0;
	lines = args_y_x[0];
	map = malloc((lines - 1) * sizeof(char *));
	while (lines > i)
	{
		map[i] = malloc(args_y_x[1] * sizeof(char));
		i++;
	}
	return (asigned_map(map, buffer));
}

void	clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
