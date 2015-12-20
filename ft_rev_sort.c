/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 06:30:47 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:46:51 by pbompard         ###   ########.fr       */
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
	int			i;

	i = 0;
	while (list->data[i] && list->next->data[i] && \
			list->data[i] == list->next->data[i])
		i++;
	if (!(list->data[i]) || (list->data[i] < list->next->data[i]))
		sort_diff(e, list);
}

void			ft_rev_sort(t_env *e, t_elem *list)
{
	t_elem		*begin;

	begin = list;
	while (e->boolean == 1)
	{
		e->boolean = 0;
		while (list->next != NULL)
		{
			if (list->data && list->next->data)
			{
				if (list->data[0] == list->next->data[0])
					sort_equ(e, list);
				else if (list->data[0] < list->next->data[0])
					sort_diff(e, list);
			}
			list = list->next;
		}
		list = begin;
	}
}
