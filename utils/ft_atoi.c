/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:52:44 by esantana          #+#    #+#             */
/*   Updated: 2024/07/08 22:24:50 by esantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// TODO: check if this shit works please//
int ft_atoi(const char *str) {
    int result = 0;
    int sign = 1;

    // Handle negative numbers, adds -1 to multiply it after parse
    if (*str == '-') {
        sign = -1;
        str++;
    }

    // Convert string to integer while str exist
    while (*str) {
        if (*str < '0' || *str > '9') break; // Do we have to check if its a number??
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}
