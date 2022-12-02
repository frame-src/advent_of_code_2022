/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:23:02 by frmessin          #+#    #+#             */
/*   Updated: 2022/03/31 12:09:43 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	sub;
	size_t			i;

	sub = c;
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = sub;
		i++;
	}
	return (b);
}
