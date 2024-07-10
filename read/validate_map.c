#include "../file_options.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct
{
	int			*y_x;
	char		*chars;
	char		**map;
}				s_file_options;
*/
char			**create_map(char *buffer, int *args_y_x);
char			*ft_process_file(char *file_name);
void			extract_values_from_first_line(char *buffer, int *intValue,
					char *chars);

int				count_lines(char *buffer);
int				find_newline_pos(char *str);

int	validate_characters_cols(char *buffer, char *chars)
{
	int	i;
	int	cols;
	int	temp_col;

	(void)*chars;
	i = find_newline_pos(buffer);
	cols = 0;
	i++;
	while (buffer[i] != '\n')
	{
		cols++;
		i++;
	}
	i++;
	temp_col = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (temp_col != cols)
			{
				printf("Error columns %d, %d \n", cols, temp_col);
				exit(1);
			}
			else
				temp_col = 0;
		}
		else if (buffer[i] != chars[0] && buffer[i] != chars[1])
		{
			printf("Error chararacters: %c\n", buffer[i]);
			exit(1);
		}
		else
			temp_col++;
		i++;
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
	{
		printf("Error count lines");
		exit(1);
	}
	options[0].y_x[0] = int_value;
	options[0].y_x[1] = validate_characters_cols(buff, chars);
	options[0].chars = chars;
	options[0].map = create_map(buff, options[0].y_x);
	return (options[0]);
}