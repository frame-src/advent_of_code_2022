/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:30 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/16 17:00:34 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in(char const a, char const *val)
{
	size_t	i;

	i = 0;
	while (val[i])
	{
		if (a == val[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_setstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (ft_in(s1[i], set) == 1)
	{
		start = start + 1;
		i++;
	}
	return (start);
}

static size_t	ft_setend(char const *s1, char const *set, size_t start)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = 0;
	while ((start < (ft_strlen(s1) - i))
		&& ft_in(s1[ft_strlen(s1) - 1 - i], set) == 1)
	{
		end = end + 1;
		i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	start = ft_setstart (s1, set);
	end = ft_setend (s1, set, start);
	rtn = malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
	if (rtn == NULL)
		return (NULL);
	rtn = ft_memcpy(rtn, s1 + start, ft_strlen(s1) - start - end);
	rtn[ft_strlen(s1) - start - end] = '\0';
	return (rtn);
}
