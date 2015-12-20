/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:15:50 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/27 23:20:41 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem				*create_all_elem(t_env *e, char *target)
{
	struct dirent	*reader;
	DIR				*a;
	t_elem			*new;

	new = create_elem(NULL);
	a = opendir(target);
	if (e->flags & A_FLAG)
		while ((reader = readdir(a)))
		{
			new = add_end(&new, reader->d_name);
			// printf("ADD = '%s'\n", reader->d_name);
		}
	else
		while ((reader = readdir(a)))
		{
			if (reader->d_name[0] != '.')
				new = add_end(&new, reader->d_name);
			// printf("ADD = '%s'\n", reader->d_name);
		}
	closedir(a);
	return (new);
}
