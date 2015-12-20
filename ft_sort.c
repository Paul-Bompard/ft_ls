/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:40:20 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:47:25 by pbompard         ###   ########.fr       */
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
	if (list->data[i] > list->next->data[i] || !(list->next->data))
{
				// printf("COUCOU\n");
		sort_diff(e, list);
}}

void		 	ft_sort(t_env *e, t_elem *list)
{
	t_elem		*begin;

	begin = list;
	while (e->boolean == 1)
	{
		e->boolean = 0;


		// while (list->next != NULL)
		// {
		// 	printf("%s\n", list->data);
		// 	list = list->next;
		// }

		while (list->next != NULL)
		{
			if (list->data && list->next->data)
			{
				// if (list->data[0] == list->next->data[0])
					sort_equ(e, list);
				// else if (list->data[0] > list->next->data[0])
				// 	sort_diff(e, list);
			}
			list = list->next;
		}
		list = begin;
	}
}
