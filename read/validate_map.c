/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:26:03 by varias-c          #+#    #+#             */
/*   Updated: 2024/07/10 20:43:28 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "file_options.h"

/*
typedef struct
{
	int			*y_x;
	char		*chars;
	char		**map;
}				s_file_options;
*/
int	validate_characters_cols(char *buffer, char *chars)
{
	int	i;
	int	cols;
	int	temp_col;

	(void)*chars;
	i = find_newline_pos(buffer);
	cols = 0;
	while (buffer[++i] != '\n')
		cols++;
	temp_col = 0;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
		{
			if (temp_col != cols)
				ft_error("Columns");
			else
				temp_col = 0;
		}
		else if (buffer[i] != chars[0] && buffer[i] != chars[1])
			ft_error("Characters");
		else
			temp_col++;
	}
	return (cols);
}

t_file_options	validate_map(char *file_name)
{
	char			*buffer;
	t_file_options	*options;
	char			chars[3];
	int				int_value;
	char			*buff;

	options = (t_file_options *)malloc(3 * sizeof(int));
	buffer = ft_process_file(file_name);
	buff = buffer;
	extract_values_from_first_line(buffer, &int_value, chars);
	if (count_lines(buffer) != int_value)
		ft_error("count lines");
	options[0].y_x[0] = int_value;
	options[0].y_x[1] = validate_characters_cols(buff, chars);
	options[0].chars = chars;
	options[0].map = create_map(buff, options[0].y_x);
	return (options[0]);
}
