/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:04:06 by pbompard          #+#    #+#             */
/*   Updated: 2015/12/11 15:04:07 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive(t_env *e, t_elem *list, char *target)
{
	t_elem		*tmp;

	while (list->next != NULL)
	{
		list = list->next;
		printf("target = %s\n", ft_strjoin(ft_strjoin(target, "/"), list->data));
		if (list->type == 'd' && opendir(ft_strjoin(ft_strjoin(target, "/"), list->data)))
		{
			tmp = create_all_elem(e, ft_strjoin(ft_strjoin(target, "/"), list->data));
			what_flags(e, tmp);
			recursive(e, tmp, ft_strjoin(ft_strjoin(target, "/"), list->data));
		}
	}
}