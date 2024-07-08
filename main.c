#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char	*ft_process_file(char *file_name);
//square matrix_iterator(**char matrix, char *simbols, unsigned int x, unsigned int y)
/*
    square = {
        int x;
        int y;
        int n;
    }
*/

int	main(int argc, char *argv[])
{
    char	*map;

    if(argc != 2)
        {
            // arguments invalid
            exit(1);
        }

    map = ft_process_file(argv[1]);

    printf("%s\n", map);
    free(map);
    return (0);
}
