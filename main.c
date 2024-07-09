#include "bsq.h"

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
    int y_x[] = {9, 27};

    if (argc != 2)
    {
        // arguments invalid
        exit(1);
    }
    map = validate_map(argv[1]);
    ft_print_map(map, y_x);
    free(map);
    return (0);
}
