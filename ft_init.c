/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 15:37:50 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:13:01 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_init(t_env *e, int argc, char **argv)
{
	e->ac = argc;
	e->av = argv;
	e->boolean = 1;
	e->flags = 0;
	e->err_flags = 0;
	e->i = 0;
	e->len_links = 0;
	e->len_owner = 0;
	e->len_group = 0;
	e->len_size = 0;


}
