/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:21:37 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/16 16:26:07 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char	*rstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		rstr = ft_calloc (sizeof(char), 1);
		if (!rstr)
			return (NULL);
		return (rstr);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	rstr = (char *)malloc((len + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	ft_strlcpy(rstr, s + start, len + 1);
	return (rstr);
}
