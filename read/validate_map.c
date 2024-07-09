#include <stdio.h>
#include <stdlib.h>

char	*ft_loadmap(int fd);
char	*ft_process_file(char *file_name);
int valid_buffer(char *buffer)
{
    (void) buffer;
    return (1);
}

char *validate_map(char *file_name)
{
    char *buffer;
    buffer = ft_process_file(file_name);
    
    printf("check buffer: %s", buffer);
    if (!valid_buffer(buffer))
    {
        printf("map error\n");
        exit(1);
    }
    return (buffer);
}