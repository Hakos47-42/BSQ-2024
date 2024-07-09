/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_options.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantana <esantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:53:11 by pabmart2          #+#    #+#             */
/*   Updated: 2024/07/09 20:52:42 by esantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OPTIONS_H
# define FILE_OPTIONS_H

struct							s_file_options
{
	int							*y_x;
	char						*chars;
	char						**map;
};
typedef struct s_file_options	*t_file_options;

#endif
