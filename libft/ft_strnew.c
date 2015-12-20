/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:14:41 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:18:18 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strnew(size_t size)
{
	void		*str;

	str = (void *)ft_memalloc(size + 1);
	if (str == NULL)
		return ((char *)NULL);
	else
		return ((char *)str);
}
