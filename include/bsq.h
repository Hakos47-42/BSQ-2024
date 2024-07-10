/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:53:11 by varias-c          #+#    #+#             */
/*   Updated: 2024/07/10 20:45:59 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "file_options.h"
# include "square.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_strlen(char *str);
void			clean_map(char **map);
void			ft_print_map(char **map, unsigned int *y_x);
void			print_error_and_close_fd(char *message, int fd);
char			*resize_buffer(char *buffer, int *capacity, int size, int fd);
char			*read_from_file(int fd, char *buffer, int *size, int *capacity);
char			*ft_loadmap(int fd);
char			*ft_process_file(char *file_name);
int				ft_atoi(const char *str);
void			print_str(const char *str);
int				count_lines(char *buffer);
char			*find_newline(char *str);
int				find_newline_pos(char *str);
int				custom_atoi(const char *str);
void			extract_values_from_first_line(char *buffer, int *intValue,
					char *chars);
char			**asigned_map(char **map, char *buffer);
char			**create_map(char *buffer, unsigned int *args_y_x);
void			clean_map(char **map);
int				validate_characters_cols(char *buffer, char *chars);
char			**valid_buffer(char *buffer);
t_file_options	validate_map(char *file_name);
int				ft_atoi(const char *str);
void			print_str(const char *str);
int				check_obstacles(char **matrix, char symbols[],
					unsigned int coords[], unsigned int diagonal_size);
int				diagonal_check(char **matrix, char symbols[],
					unsigned int origin[], unsigned int size[]);
void			update_square(t_square square, unsigned int tmp_dimension,
					unsigned int origin_yx[]);
t_square		matrix_iterator(char **matrix, char symbols[],
					unsigned int size[]);
void			fill_matrix(char **matrix, char fill_symbol, t_square square);
void			ft_error(char *text);

#endif
