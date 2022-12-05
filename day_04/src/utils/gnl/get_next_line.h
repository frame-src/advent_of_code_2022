/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:01:38 by frmessin          #+#    #+#             */
/*   Updated: 2022/05/26 14:19:50 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

char	*read_file( int fd, char *string);
char	*get_next_line(int fd);
size_t	chr_src(char *str, char c);
size_t	str_len(char *str);
char	*make_string(char *tail, char *head, size_t n_byte);
char	*ft_cpy(int j, char *str, char *tail, char *head);
char	*ft_return_string(char *string, char *buff);

#endif