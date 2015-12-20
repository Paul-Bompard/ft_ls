/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:40:24 by pbompard          #+#    #+#             */
/*   Updated: 2014/12/16 18:23:14 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				option_un(void)
{
	struct dirent	*reader;
	DIR				*a;
	t_elem			*new;

	new = create_elem(NULL);
	a = opendir(".");
	while ((reader = readdir(a)))
		if (reader->d_name[0] != '.')
			new = add_end(&new, reader->d_name);
	while (new->next != NULL)
	{
		ft_putendl(new->next->data);
		new = new->next;
	}
	closedir(a);
}
