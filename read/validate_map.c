#include <stdio.h>
#include <stdlib.h>

char	*ft_process_file(char *file_name);
void extract_values_from_first_line(char *buffer, int *intValue, char *chars);

int count_lines(char *buffer);
int find_newline_pos(char *str);

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

int valid_buffer(char *buffer)
{
    //(void) buffer;
    char chars[3];
    int c_lines = count_lines(buffer);
    int intValue;
    int col;
    char *buff;

    buff = buffer;
    extract_values_from_first_line(buffer, &intValue, chars);
    if (c_lines != intValue)
    {
        printf("Error count lines");
        exit(1);
    }
    col = validate_characters_cols(buff, chars);
    printf("intValue: %d\n", intValue);
    printf("characters %s \n", chars);
    printf("cols %d\n", col);
    return (1);
}

char *validate_map(char *file_name)
{
    char *buffer;
    buffer = ft_process_file(file_name);
    if (!valid_buffer(buffer))
    {
        printf("map error\n");
        exit(1);
    }
    return (buffer);
}