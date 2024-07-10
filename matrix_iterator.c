/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_iterator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:06:29 by pabmart2          #+#    #+#             */
/*   Updated: 2024/07/08 19:06:45 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct					s_square
{
	int					x;
	int					y;
	int					dimension;
};

typedef struct s_square	*t_square;

t_square	matrix_iterator(char **matrix, char symbols[], int x,
		int y)
{
	int			count_x;
	int			count_y;
	int			tmp_dimension;
	t_square	square;

	square = (t_square *)malloc(3 * sizeof(int));
	square->dimension = 0;
	count_x = 0;
	count_y = 0;
	while (count_y < y)
	{
		while (count_x < x)
		{
			if (matrix[count_y][count_x] == symbols[0])
			{
				tmp_dimension = check_obstacles(count_x, count_y);
				if (tmp_dimension > square->dimension)
				{
					square->dimension = tmp_dimension;
					square->x = count_x;
					square->y = count_y;
				}
			}
			count_x++;
		}
		count_y++;
	}
	return (square);
}
