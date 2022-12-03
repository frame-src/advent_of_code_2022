/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:24:16 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/11 02:37:42 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	spaceleft;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	spaceleft = dstsize - lendst - 1;
	if (lendst >= dstsize)
		return (dstsize + lensrc);
	if (lensrc <= spaceleft)
	{
		ft_memcpy((dst + lendst), src, lensrc + 1);
	}
	else
	{
		ft_memcpy((dst + lendst), src, spaceleft);
		dst[dstsize -1] = '\0';
	}
	return (lendst + lensrc);
}
