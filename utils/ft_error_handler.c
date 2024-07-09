/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:35:58 by esantana          #+#    #+#             */
/*   Updated: 2024/07/08 22:29:14 by esantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/**Prints an array of chars */
void	print_str(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
