#include "bsq.h"

void ft_print_map(char **map,int *y_x)
{
    int j = 0;
    int i = 0;
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

char **asigned_map(char **map, char *buffer)
{
    int i;
    int lines;
    int col;
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

char **create_map(char *buffer, int *args_y_x)
{
    char **map;
    int lines;
    int i;

    i = 0;
    lines = args_y_x[0];

    map = malloc((lines -1) * sizeof(char *));
    while (lines > i)
    {
        map[i] = malloc(args_y_x[1] * sizeof(char));
        i++;
    }
    return (asigned_map(map, buffer));
}

void clean_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
