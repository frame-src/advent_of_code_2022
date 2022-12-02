/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:04:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/11 02:44:06 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = ft_strlen((char *)s1);
	dup = malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup = ft_memcpy (dup, s1, i);
	dup[i] = '\0';
	return (dup);
}
