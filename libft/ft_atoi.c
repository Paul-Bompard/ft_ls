/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:40 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:14:59 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+' || *str <= 32)
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (sign * res);
		res = res * 10 + *str++ - '0';
	}
	return (sign * res);
}
