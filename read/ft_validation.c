/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andloren <andloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:30:29 by esantana          #+#    #+#             */
/*   Updated: 2024/07/10 20:33:34 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../constants/error_messages.h"
#include "bsq.h"

#define BUFFER_SIZE 1024

int	count_lines(char *buffer)
{
	int	i;
	int	lines;

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
char	*find_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

// Helper function to find the first occurrence of '\n' in a string
int	find_newline_pos(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

// Placeholder for custom_atoi function
// (implement according to your requirements)
int	custom_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// Updated function to extract values and ensure unique characters,
// form the first line in the example.map
void	extract_values_from_first_line(char *buffer,
		int *int_value, char *chars)
{
	int		newline_pos;
	int		i;
	char	int_str[10];

	i = -1;
	while (++i < 10)
		int_str[i] = 0;
	newline_pos = find_newline_pos(buffer);
	if (newline_pos == -1)
		ft_error(ERR_CHARS_REPEATED);
	chars[0] = buffer[newline_pos - 3];
	chars[1] = buffer[newline_pos - 2];
	chars[2] = buffer[newline_pos - 1];
	chars[3] = '\0';
	if (chars[0] == chars[1] || chars[0] == chars[2] || chars[1] == chars[2])
		ft_error("Characters must be unique.");
	i = 0;
	while (i < (newline_pos - 3))
	{
		int_str[i] = buffer[i];
		i++;
	}
	*int_value = ft_atoi(int_str);
}
