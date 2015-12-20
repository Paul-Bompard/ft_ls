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
		// else if (line[pos] == 'f')
		//     e->flags |= F_FLAG;
		// else if (line[pos] == 'g')
		//     e->flags |= G_FLAG;
		else
		{
			e->err_flags = line[pos];
			e->flags = 0b10000000;
			break;
		}
		++pos;
	}
	return (e->flags);
}

static void	put_flags(t_env *e)
{
	if (e->flags & 0b10000000)
		ft_error(0, e->err_flags, NULL, 1);
	// if (e->flags & L_FLAG)
	// 	printf("The flag 'l' is on\n");
	// else
	// 	printf("The flag 'l' is off\n");
	// if (e->flags & A_FLAG)
	// 	printf("The flag 'a' is on\n");
	// else
	// 	printf("The flag 'a' is off\n");
	// if (e->flags & R_FLAG)
	// 	printf("The flag 'r' is on\n");
	// else
	// 	printf("The flag 'r' is off\n");
	if (e->flags & UR_FLAG)
		printf("The flag 'R' is on\n");
	// else
	// 	printf("The flag 'R' is off\n");
	// if (e->flags & T_FLAG)
	// 	printf("The flag 't' is on\n");
	// else
	// 	printf("The flag 't' is off\n");
	// if (e->flags & F_FLAG)
	// 	printf("The flag 'f' is on\n");
	// else
	// 	printf("The flag 'f' is off\n");
	// if (e->flags & G_FLAG)
	// 	printf("The flag 'g' is on\n");
	// else
	// 	printf("The flag 'g' is off\n");
}

void		binary_flag(t_env *e)
{
	// printf("sizeof(e->pur_flags) - 1 = %lu\n", sizeof(e->pur_flags) - 1);
	// printf("ft_strlen(e->pur_flags) = %d\n", ft_strlen(e->pur_flags));
	e->flags = set_flags(e->pur_flags, ft_strlen(e->pur_flags), e);
	put_flags(e);
}