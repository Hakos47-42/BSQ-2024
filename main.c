#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//char *ft_process_file(char *file_name);
char **validate_map(char *file_name);
void clean_map(char **map);
void ft_print_map(char **map);
// square matrix_iterator(**char matrix, char *simbols, int *size_yx)
/*
    square = {
        int x;
        int y;
        int n;
    }
*/

int main(int argc, char *argv[])
{
    char **map;

    if (argc != 2)
    {
        // arguments invalid
        exit(1);
    }
    map = validate_map(argv[1]);
    ft_print_map(map);
    free(map);
    return (0);
}
