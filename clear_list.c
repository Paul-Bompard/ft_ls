/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:11:51 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/27 23:21:35 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		clear_list(t_elem **begin_list)
{
	t_elem	*temp;

	temp = *begin_list;
	temp = temp->next;
	while (temp->next != NULL)
	{
		free(temp);
		temp = temp->next;
	}
	free(temp);
}
