/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:33:07 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/13 00:30:06 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long int n)
{
	int			count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_result(char *str, long int n, int last)
{
	while (n != 0)
	{
		str[last - 1] = (char)(n % 10 + (int) '0');
		n = n / 10;
		last--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	ln;
	int			i;

	ln = n;
	i = ft_size(ln);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		ln = -1 * ln;
	}
	return (ft_result(str, ln, i));
}
