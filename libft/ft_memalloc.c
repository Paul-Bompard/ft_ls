/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:26:59 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:15:13 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	size_t			i;
	char			*init;

	i = 0;
	mem = (void *)malloc(size);
	init = (char *)mem;
	if (mem != NULL)
		while (i++ < size)
			*init++ = 0;
	return (mem);
}
