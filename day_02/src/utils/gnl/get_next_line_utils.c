/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:01:21 by frmessin          #+#    #+#             */
/*   Updated: 2022/05/26 14:09:17 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_cpy( int j, char *str, char *tail, char *head)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = str_len(tail);
	while (a < i)
	{
		str[a] = tail[a];
		a++;
	}
	while (a < i + j)
	{
		str[a] = head[a - i];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_return_string(char *string, char *buff)
{
	string = make_string(string, buff, -1);
	free (buff);
	buff = NULL;
	return (string);
}

size_t	chr_src(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
