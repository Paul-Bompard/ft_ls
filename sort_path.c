/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:44:00 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/30 10:10:28 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		rev_sort(t_env *e, int i, int j, int boolean)
{
	char		*tmp;

	while (boolean == 1)
	{
		boolean = 0;
		while (e->targets[i] && e->targets[i + 1])
		{
			while (e->targets[i][j] && e->targets[i + 1][j] && \
					e->targets[i][j] == e->targets[i + 1][j])
				j++;
			if (!(e->targets[i][j]) || \
				(e->targets[i][j] < e->targets[i + 1][j]))
			{
				tmp = e->targets[i + 1];
				e->targets[i + 1] = e->targets[i];
				e->targets[i] = tmp;
				boolean = 1;
			}
			i++;
			j = 0;
		}
		i = 0;
	}
}

static void		simple_sort(t_env *e, int i, int j, int boolean)
{
	char		*tmp;

	while (boolean == 1)
	{
		boolean = 0;
		while (e->targets[i] && e->targets[i + 1])
		{
			while (e->targets[i][j] && e->targets[i + 1][j] && \
					e->targets[i][j] == e->targets[i + 1][j])
				j++;
			if (!(e->targets[i + 1][j]) || \
				(e->targets[i][j] > e->targets[i + 1][j]))
			{
				tmp = e->targets[i + 1];
				e->targets[i + 1] = e->targets[i];
				e->targets[i] = tmp;
				boolean = 1;
			}
			i++;
			j = 0;
		}
		i = 0;
	}
}

void			sort_path(t_env *e)
{
	int			i;
	int			j;
	int			boolean;

	i = 0;
	j = 0;
	boolean = 1;
	if (e->flags & R_FLAG)
		rev_sort(e, i, j, boolean);
	else
		simple_sort(e, i, j, boolean);
}
