/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andloren <andloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:30:29 by esantana          #+#    #+#             */
/*   Updated: 2024/07/09 20:50:03 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "../constants/error_messages.h"

#define BUFFER_SIZE 1024

int count_lines(char *buffer)
{
	int i;
	int lines;
	lines = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			lines++;	
		i++;
	}
	return (lines - 1);
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
	int i;

	i = 0;
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
	chars[3] = '\0';
	// Check for unique characters, optimice it (?)
	if (chars[0] == chars[1] || chars[0] == chars[2] || chars[1] == chars[2])
	{
		printf("Error: Characters must be unique.\n");
		return;
	}
	// Extract integer value from line
	char intStr[10] = {0}; // TODO: norminette?? Tamaño máximo??//
	while (i < (newlinePos - 3))
	{
		intStr[i] = buffer[i];
		i ++;
	}
	// Parse value to int from retrieved array char(0-9)
	*intValue = ft_atoi(intStr);
}
