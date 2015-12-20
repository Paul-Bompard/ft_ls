/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 06:40:49 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/24 07:15:53 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_diff(t_env *e, t_elem *list)
{
	char		*tmp;

	tmp = list->next->data;
	list->next->data = list->data;
	list->data = tmp;
	e->boolean = 1;
}

static void		sort_equ(t_env *e, t_elem *list)
{
	int				i;

	i = 0;
	while (list->data[i] && list->next->data[i] && \
			list->data[i] == list->next->data[i])
		i++;
	if (list->data[i] > list->next->data[i])
		sort_diff(e, list);
}

static void		assign_path(t_env *e, t_elem *list)
{
	e->boolean = 0;
	while (list && list->next != NULL)
	{
		if (list->data && list->next->data)
		{
			ft_stats("now", e, list);
			ft_stats("next", e, list);
			if (e->stt->st_mtime == e->sttn->st_mtime)
				sort_equ(e, list);
			else if (e->stt->st_mtime < e->sttn->st_mtime)
				sort_diff(e, list);
		}
		list = list->next;
	}
}

void			ft_date_sort(t_env *e, t_elem *list)
{
	t_elem		*begin;

	// free(e->stt);
	// free(e->sttn);
	e->stt = malloc(sizeof(struct stat));
	e->sttn = malloc(sizeof(struct stat));
	begin = list;
	while (e->boolean == 1)
	{
		assign_path(e, list);
		list = begin;
	}
}
