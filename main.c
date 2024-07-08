#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//square matrix_iterator(**char matrix, char *simbols, unsigned int x, unsigned int y)
/*
    square = {
        int x;
        int y;
        int n;
    }
*/
// Include the prototype of ft_loadmap here or include the header file where it's declared
char	*ft_loadmap(int fd);

int	main(void)
{
    int	fd;
    char	*map;

    fd = open("example", O_RDONLY); // Assuming the example context is saved in "example.txt"
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    map = ft_loadmap(fd);
    if (map == NULL)
    {
        close(fd);
        return (1);
    }
    printf("%s\n", map);
    free(map);
    close(fd);
    return (0);
}
