/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:26:43 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/16 15:25:07 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (needle[0] == '\0')
			return ((char *)haystack);
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return (&((char *)haystack)[i]);
			j++;
			if (j + i == len)
				return (NULL);
		}
		i++;
		if (haystack[i] == '\0')
			return (NULL);
	}
	return (NULL);
}
