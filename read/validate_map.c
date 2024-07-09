#include "bsq.h"

int validate_characters_cols(char *buffer, char *chars)
{
    (void) *chars;
    int i;
    int cols;
    int temp_col;
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
            } else
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
    return cols;

}

char **valid_buffer(char *buffer)
{
    char chars[3];
    int c_lines = count_lines(buffer);
    int y_x[2];
    int intValue;
    char *buff;

    buff = buffer;
    extract_values_from_first_line(buffer, &intValue, chars);
    if (c_lines != intValue)
    {
        printf("Error count lines");
        exit(1);
    }
    y_x[0] = intValue;
    y_x[1] = validate_characters_cols(buff, chars);
    return (create_map(buff, y_x));
}

char **validate_map(char *file_name)
{
    char **map;
    char *buffer;
    buffer = ft_process_file(file_name);
    map = valid_buffer(buffer);
    return (map);
}
