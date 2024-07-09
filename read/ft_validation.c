/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:30:29 by esantana          #+#    #+#             */
/*   Updated: 2024/07/08 22:29:18 by esantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../constants/error_messages.h"

#define BUFFER_SIZE 1024

int ft_atoi(const char *str);
void print_str(const char *str);

// This function counts the number of lines in a file
int count_lines(char *filename)
{
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	int lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1); // Error opening file
	lines = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		for (ssize_t i = 0; i < bytes_read; ++i)
		{
			if (buffer[i] == '\n')
				lines++;
		}
	}
	close(fd);
	return (lines);
}

// Function to find the next newline character in a string
char *find_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL); // Return NULL if newline not found
}

// Helper function to find the first occurrence of '\n' in a string
int find_newline_pos(char *str)
{
	int pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1); // Newline not found
}

// Placeholder for custom_atoi function (implement according to your requirements)
int custom_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	// Handle negative numbers
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	// Convert string to integer
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break; // Non-numeric character
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// Updated function to extract values and ensure unique characters, form the first line in the example.map
void extract_values_from_first_line(char *buffer, int *intValue, char *chars)
{
	int newlinePos;

	newlinePos = find_newline_pos(buffer);
	if (newlinePos == -1)
	{
		print_str(ERR_CHARS_REPEATED);
		return;
	}
	// Extract chars
	chars[0] = buffer[newlinePos - 3];
	chars[1] = buffer[newlinePos - 2];
	chars[2] = buffer[newlinePos - 1];
	// Check for unique characters, optimice it (?)
	if (chars[0] == chars[1] || chars[0] == chars[2] || chars[1] == chars[2])
	{
		printf("Error: Characters must be unique.\n");
		return;
	}
	// Extract integer value from line
	char intStr[10] = {0}; // TODO: norminette?? Tamaño máximo??//
	for (int i = 0; i < newlinePos - 3; i++)
	{
		intStr[i] = buffer[i];
	}
	// Parse value to int from retrieved array char(0-9)
	*intValue = ft_atoi(intStr);
}
