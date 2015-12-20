/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:44:56 by pbompard          #+#    #+#             */
/*   Updated: 2015/12/11 15:44:59 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int argc, char **argv)
{
	t_env		e;
	t_elem		*list;

	ft_init(&e, argc, argv);
	flag_extract(&e);
	while (e.targets[e.i] && (e.boolean = 1))
	{
		e.stt = malloc(sizeof(struct stat));
		e.sttn = malloc(sizeof(struct stat));
		list = create_all_elem(&e, e.targets[e.i]);
		what_flags(&e, list);
		e.i += 1;
		clear_list(&list);
		e.len_links = 0;
		e.len_owner = 0;
		e.len_group = 0;
		e.len_size = 0;
		free(e.stt);
		free(e.sttn);
	}
	return (0);
}
