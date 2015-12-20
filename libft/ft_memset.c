/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:46:49 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:15:22 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*p_b;

	p_b = b;
	while (len--)
	{
		*p_b = (unsigned char)c;
		p_b++;
	}
	return (b);
}
