/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 18:18:14 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 07:01:23 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		set_flags(char *line, int len, t_env *e)
{
	int			pos;

	pos = 0;
	while (pos < len)
	{
		if (line[pos] == 'l')
			e->flags |= L_FLAG;
		else if (line[pos] == 'a')
			e->flags |= A_FLAG;
		else if (line[pos] == 'r')
			e->flags |= R_FLAG;
		else if (line[pos] == 'R')
			e->flags |= UR_FLAG;
		else if (line[pos] == 't')
			e->flags |= T_FLAG;
		else
		{
			e->err_flags = line[pos];
			e->flags = 0b10000000;
			break ;
		}
		++pos;
	}
	return (e->flags);
}

static void		put_flags(t_env *e)
{
	if (e->flags & 0b10000000)
		ft_error(0, e->err_flags, NULL, 1);
}

void			binary_flag(t_env *e)
{
	e->flags = set_flags(e->pur_flags, ft_strlen(e->pur_flags), e);
	put_flags(e);
}
