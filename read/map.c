#include <stdlib.h>

char **asigned_map(char **map, char *buffer)
{
    int i;
    int lines;
    int col;
    int init;

    init = 1;
    i = 0;
    lines = 0;
    col = 0;
    while (buffer[i])
    {
        if (buffer[i] != '\n' && init != 1)
            map[lines][col] = buffer[i];
        else if (buffer[i] == '\n')
        {
            init = 0;
            col = 0;
            lines++;
        }
        i++;
    }
    return (map);
}

char **create_map(char *buffer, int *args_x_y)
{
    char **map;
    int lines;
    int i;

    i = 0;
    lines = args_x_y[1];

    map = malloc(lines * sizeof(int));
    while (lines >= i)
    {
        map[i] = malloc(args_x_y[0] * sizeof(int));
    }
    return (asigned_map(map, buffer));
}
