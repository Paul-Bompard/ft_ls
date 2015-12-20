/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:39:02 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/27 23:46:34 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			otoi(unsigned int n)
{
	int		rem;
	int		i;
	int		octal;

	i = 1;
	octal = 0;
	while (n != 0)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
	}
	return (octal);
}
