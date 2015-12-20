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

void			stat_lstat(struct stat *stats, t_env *e, t_elem *list)
{
	stats = ft_stats("now", e, list, stats);
	if (stats->st_mode & S_IFMT)
	{
		if (S_ISDIR(stats->st_mode))
			list->type = 'd';
		else if (S_ISLNK(stats->st_mode))
		{
			list->mode_link = '@';
			list->type = 'l';
		}
		else if ((stats->st_mode & 0170000) == 0020000)
			list->type = 'c';
		else if ((stats->st_mode & 0170000) == 0060000)
			list->type = 'b';
		else if ((stats->st_mode & 0170000) == 0010000)
			list->type = 'p';
		else if ((stats->st_mode & 0170000) == 0140000)
			list->type = 's';
		else
			list->type = '-';
	}
	// ft_lstat_more(stats, list);
}