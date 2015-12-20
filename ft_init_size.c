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

void	ft_init_size(int i, t_env *e, char *str)
{
	if (!ft_strcmp(str, "links") && i > e->len_links)
		e->len_links = i;
	else if (!ft_strcmp(str, "owner") && i > e->len_owner)
		e->len_owner = i;
	else if (!ft_strcmp(str, "group") && i > e->len_group)
		e->len_group = i;
	else if (!ft_strcmp(str, "size") && i > e->len_size)
		e->len_size = i;
}
