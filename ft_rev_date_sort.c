/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_date_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 06:41:00 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/24 07:15:49 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_diff(t_env *e, t_elem *list)
{
	char			*tmp;

	tmp = list->next->data;
	list->next->data = list->data;
	list->data = tmp;
	e->boolean = 1;
}

static void			sort_equ(t_env *e, t_elem *list)
{
	int				i;

	i = 0;
	while (list->data[i] && list->next->data[i] && \
			list->data[i] == list->next->data[i])
		i++;
	if (list->data[i] < list->next->data[i])
		sort_diff(e, list);
}

static void			assign_path(t_env *e, t_elem *list,\
							 struct stat *stt, struct stat *sttn)
{
	e->boolean = 0;
	while (list->next != NULL)
	{
		if (list->data && list->next->data)
		{
			stt = ft_stats("now", e, list, stt);
			sttn = ft_stats("next", e, list, sttn);
			if (stt->st_mtime == sttn->st_mtime)
				sort_equ(e, list);
			else if (stt->st_mtime > sttn->st_mtime)
				sort_diff(e, list);
		}
		list = list->next;
	}
}

void		 		ft_rev_date_sort(t_env *e, t_elem *list)
{
	t_elem			*begin;
	struct stat		*stt;
	struct stat		*sttn;

	stt = malloc(sizeof(struct stat));
	sttn = malloc(sizeof(struct stat));
	begin = list;
	while (e->boolean == 1)
	{
		assign_path(e, list, stt, sttn);
		list = begin;
	}
}
