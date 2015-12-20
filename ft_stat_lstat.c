/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat_lstat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:55:37 by pbompard          #+#    #+#             */
/*   Updated: 2015/12/11 12:55:39 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stat_lstat(t_env *e, t_elem *list)
{
	free(e->stt);
	e->stt = malloc(sizeof(struct stat));
	ft_stats("now", e, list);
	if (e->stt->st_mode & S_IFMT)
	{
		if (S_ISDIR(e->stt->st_mode))
			list->type = 'd';
		else if (S_ISLNK(e->stt->st_mode))
		{
			list->mode_link = '@';
			list->type = 'l';
		}
		else if ((e->stt->st_mode & 0170000) == 0020000)
			list->type = 'c';
		else if ((e->stt->st_mode & 0170000) == 0060000)
			list->type = 'b';
		else if ((e->stt->st_mode & 0170000) == 0010000)
			list->type = 'p';
		else if ((e->stt->st_mode & 0170000) == 0140000)
			list->type = 's';
		else
			list->type = '-';
	}
}
