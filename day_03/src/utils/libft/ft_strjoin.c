/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:58:07 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/16 17:00:17 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *) malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (newstr == NULL)
		return (NULL);
	ft_strlcat(ft_memmove(newstr, s1, ft_strlen(s1) + 1),
		s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	return (newstr);
}
