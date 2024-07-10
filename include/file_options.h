/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_options.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:53:11 by pabmart2          #+#    #+#             */
/*   Updated: 2024/07/10 20:21:52 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OPTIONS_H
# define FILE_OPTIONS_H

typedef struct s_file_options
{
	unsigned int	y_x[2];
	char			*chars;
	char			**map;
}					t_file_options;

#endif
