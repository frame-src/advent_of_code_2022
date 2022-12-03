/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:56:36 by frmessin          #+#    #+#             */
/*   Updated: 2022/04/12 21:16:33 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char p)
{
	if (((p >= '\t' && p <= '\r' ) || p == ' ') && p != '\0')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		rval;
	int		sign;

	sign = 1;
	rval = 0;
	while (ft_isspace(*str))
	{
		str++;
	}
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		rval = (rval * 10) + (*str - '0');
		str++;
	}
	return (sign * rval);
}
