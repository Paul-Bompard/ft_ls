/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 02:31:33 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:54:10 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_corresp(char *corresp, t_env *e)
{
	int			i;

	i = 0;
	if (!ft_strcmp(corresp, "links"))
		i = e->len_links;
	else if (!ft_strcmp(corresp, "owner"))
		i = e->len_owner;
	else if (!ft_strcmp(corresp, "group"))
		i = e->len_group;
	else if (!ft_strcmp(corresp, "size"))
		i = e->len_size;
	return (i);
}

void			ft_indent(char *str, t_env *e, char *corresp)
{
	int			i;

	i = ft_corresp(corresp, e);
	if (!ft_strcmp(corresp, "links") || !ft_strcmp(corresp, "size"))
	{
		while (i != ft_strlen(str))
		{
			write(1, " ", 1);
			i--;
		}
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		while (i != ft_strlen(str))
		{
			write(1, " ", 1);
			i--;
		}
	}
}
