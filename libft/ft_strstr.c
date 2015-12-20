/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:08:01 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:18:32 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char *ft_strstr1(int a, int x, int y, const char *s1)
{
	while (a++ < x - y)
		s1++;
	return ((char*)s1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		y;
	int		x;
	int		a;

	y = 0;
	x = 0;
	a = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[x] != '\0')
	{
		if (s1[x] == s2[y])
			y++;
		else if (y > 0)
		{
			x--;
			y = 0;
		}
		x++;
		if (s2[y] == '\0')
			return (ft_strstr1(a, x, y, s1));
	}
	return (NULL);
}
