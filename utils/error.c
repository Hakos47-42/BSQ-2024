/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:19:32 by varias-c          #+#    #+#             */
/*   Updated: 2024/07/10 20:21:15 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_error(char *text)
{
	write(2, "Error:", 6);
	while (*text)
	{
		write(2, &text[0], 1);
		text++;
	}
	write(2, "\n", 1);
	exit(1);
}