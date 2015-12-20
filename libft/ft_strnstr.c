/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:25:28 by pbompard          #+#    #+#             */
/*   Updated: 2014/11/22 18:18:23 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (ft_strlen((char *)s2) > (int)n)
		return (NULL);
	i = 0;
	j = 0;
	while (s2[j] && n > 0)
	{
		while ((s1[i] == s2[j]) && s2[j])
		{
			i++;
			j++;
		}
		if (ft_strlen((char *)s2) == j)
			return ((char *)s1 + i - j);
		else
			i = i - j + 1;
		j = 0;
		n--;
	}
	return (NULL);
}
