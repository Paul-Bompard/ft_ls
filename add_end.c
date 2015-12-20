/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:06:26 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/27 23:11:00 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*add_end(t_elem **begin_list, char *data)
{
	t_elem	*newelement;
	t_elem	*temp;

	temp = *begin_list;
	newelement = (t_elem *)malloc(sizeof(t_elem));
	newelement->data = data;
	newelement->next = NULL;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newelement;
	}
	return (*begin_list);
}
