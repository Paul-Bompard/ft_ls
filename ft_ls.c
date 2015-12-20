/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 02:31:33 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:54:10 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_total(t_elem *list, t_env *e)
{
	int			i;
	char		*current_path;

	current_path = (char *)malloc(sizeof(char) * FILENAME_MAX);
	i = 0;
	while (list->next != NULL)
	{
		ft_bzero(current_path, FILENAME_MAX);
		list = list->next;
		if (e->targets[e->i][0] != '/')
		{
			getcwd(current_path, FILENAME_MAX);
			ft_strcat(current_path, "/");
		}
		ft_strcat(current_path, e->targets[e->i]);
		ft_strcat(current_path, "/");
		ft_strcat(current_path, list->data);
		if (stat(current_path, e->stt) >= 0)
			i += (e->stt->st_blocks);
		else if (lstat(list->data, e->stt) >= 0)
			i += (e->stt->st_blocks);
	}
	ft_putstr("total ");
	ft_putnbr(i);
	ft_putchar('\n');
}

static void		ft_print_ls(t_elem *list, t_env *e)
{
	if (e->flags & L_FLAG)
		ft_total(list, e);
	while (list->next != NULL)
	{
		list = list->next;
		if (e->flags & L_FLAG)
		{
			write(1, &(list->type), 1);
			write(1, list->right, 9);
			if (list->mode_link == '@')
			{
				write(1, &(list->mode_link), 1);
				write(1, " ", 2);
			}
			else
				write(1, "  ", 2);
			ft_indent(ft_itoa(list->links), e, "links");
			write(1, " ", 1);
			ft_indent(list->owner, e, "owner");
			write(1, "  ", 2);
			ft_indent(list->group, e, "group");
			write(1, "  ", 2);
			ft_indent(ft_itoa(list->size), e, "size");
			write(1, list->last_change, ft_strlen(list->last_change) - 1);
			write(1, " ", 1);
		}
		ft_putendl(list->data);
	}
	if ((e->targets[e->i + 1]))
		ft_putstr("\n");
}

void			what_flags(t_env *e, t_elem *list)
{
	static int		i = 0;

	if (e->flags & R_FLAG && !(e->flags & T_FLAG))
		ft_rev_sort(e, list);
	else if (e->flags & T_FLAG && !(e->flags & R_FLAG))
		ft_date_sort(e, list);
	else if (e->flags & T_FLAG && e->flags & R_FLAG)
		ft_rev_date_sort(e, list);
	else
		ft_sort(e, list);
	if (e->flags & L_FLAG)
		add_all_data(&list, e);
	if (e->nb_path > 1)
	{
		ft_putstr(e->targets[e->i]);
		ft_putendl(":");
	}
	ft_print_ls(list, e);
	if (e->flags & UR_FLAG && i == 0)
	{
		i++;
		recursive(e, list, e->targets[e->i]);
	}
}
