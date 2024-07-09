#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int find_newline_pos(char *str);

void ft_print_map(char **map)
{
    int i = 0;
    int j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            write(1, &map[i][j], 1);
            j++;
        }
        write(1 ,"\n", 1);
        j = 0;
        i++;
    }
}

char **asigned_map(char **map, char *buffer)
{
    int i;
    int lines;
    int col;

    i = find_newline_pos(buffer);
    lines = 0;
    col = 0;
    i++;
    printf("character : %c\n", buffer[i]);
    while (buffer[i])
    {
        if (buffer[i] != '\n')
        {
          //  printf("init line %c \n", buffer[i]);
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
    printf("create map");
    ft_print_map(map);
    printf("\n");
    return (map);
}

char **create_map(char *buffer, int *args_y_x)
{
    char **map;
    int lines;
    int i;

    i = 0;
    lines = args_y_x[0];

    map = malloc(lines * sizeof(int));
    while (lines > i)
    {
        map[i] = malloc(args_y_x[1] * sizeof(int));
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
