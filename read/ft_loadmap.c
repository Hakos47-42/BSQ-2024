/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:14:25 by esantana          #+#    #+#             */
/*   Updated: 2024/07/08 17:29:16 by esantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void	print_error_and_close_fd(char *message, int fd)
{
	write(2, message, strlen(message));
	if (fd != -1)
	{
		close(fd);
	}
}

char	*resize_buffer(char *buffer, int *capacity, int size, int fd)
{
	char	*new_buffer;

	*capacity *= 2;
	new_buffer = (char *)malloc(*capacity);
	if (new_buffer == NULL)
	{
		print_error_and_close_fd("Error reallocating memory\n", fd);
		free(buffer);
		return (NULL);
	}
	for (int cont = 0; cont < size; cont++)
	{
		new_buffer[cont] = buffer[cont];
	}
	free(buffer);
	return (new_buffer);
}

char	*read_from_file(int fd, char *buffer, int *size, int *capacity)
{
	int	bytes_read;

	while ((bytes_read = read(fd, buffer + *size, BUFFER_SIZE)) > 0)
	{
		*size += bytes_read;
		if (*size + BUFFER_SIZE > *capacity)
		{
			buffer = resize_buffer(buffer, capacity, *size, fd);
			if (buffer == NULL)
				return (NULL);
		}
	}
	return (buffer);
}

char	*ft_loadmap(int fd)
{
	char	*buffer;
	int		size = 0, capacity;

	buffer = (char *)malloc(BUFFER_SIZE);
	size = 0, capacity = BUFFER_SIZE;
	if (fd < 0)
	{
		print_error_and_close_fd("Error opening file\n", -1);
		return (NULL);
	}
	if (buffer == NULL)
	{
		print_error_and_close_fd("Error allocating memory\n", fd);
		return (NULL);
	}
	buffer = read_from_file(fd, buffer, &size, &capacity);
	if (buffer == NULL)
		return (NULL);
	// Assuming there's logic here to close the file descriptor and return the buffer
	close(fd);
	return (buffer);
}

char	*ft_process_file(char *file_name)
{
	int	fd;
	char *map;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		// error open file
		exit(1);
	}
	map = ft_loadmap(fd);
	if (map == NULL)
	{
		close(fd);
		exit(1);
	}
	return (map);
}
