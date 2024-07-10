#include "file_options.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// char *ft_process_file(char *file_name);
/*typedef struct
{
	int			*y_x;
	char		*chars;
	char		**map;
}				s_file_options;
*/
t_file_options	validate_map(char *file_name);
void			ft_print_map(char **map, int *y_x);
// square matrix_iterator(**char matrix, char *simbols, int *size_yx)
/*
	square = {
		int x;
		int y;
		int n;
	}
*/

int	main(int argc, char *argv[])
{
	t_file_options	map_options;

	if (argc != 2)
	{
		printf("error");
		exit(1);
	}
    printf("%s\n", argv[1]);
	map_options = validate_map(argv[1]);
    printf("h");
	ft_print_map(map_options.map, map_options.y_x);
	free(map_options.map);
	return (0);
}