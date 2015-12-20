/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:14:30 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/30 08:29:46 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char				*assig_right(char *right, unsigned int i)
{
	if (i == 0)
		right = ft_strjoin(right, "---");
	else if (i == 1)
		right = ft_strjoin(right, "--x");
	else if (i == 2)
		right = ft_strjoin(right, "-w-");
	else if (i == 3)
		right = ft_strjoin(right, "-wx");
	else if (i == 4)
		right = ft_strjoin(right, "r--");
	else if (i == 5)
		right = ft_strjoin(right, "r-x");
	else if (i == 6)
		right = ft_strjoin(right, "rw-");
	else
		right = ft_strjoin(right, "rwx");
	return (right);
}

static char				*stock_ctime(struct stat stats)
{
	char				**times;
	char				*hour;
	char				*tmp;

	times = ft_strsplit(ctime(&stats.st_mtime), ' ');
	tmp = " ";
	tmp = ft_strjoin(tmp, times[1]);
	tmp = ft_strjoin(tmp, " ");
	if (times[2][1] <= 10)
		tmp = ft_strjoin(tmp, " ");
	tmp = ft_strjoin(tmp, times[2]);
	tmp = ft_strjoin(tmp, " ");
	if (((int)stats.st_mtime + 15778463) >= time(NULL))
	{
		hour = ft_strsub(times[3],0,5);
		tmp = ft_strjoin(tmp, hour);
	}
	else
	{
		tmp = ft_strjoin(tmp, " "); 
		tmp = ft_strjoin(tmp, ft_strsub(times[4],0,4));
	}
	tmp = ft_strjoin(tmp, " "); 
	return (tmp);
}

static void				get_all(t_elem *list, struct stat stats, t_env *e)
{
	struct group		*grp;
	struct passwd		*pwd;
	unsigned int		gid;
	unsigned int		uid;
	unsigned int		i_right;

	gid = stats.st_gid;
	uid = stats.st_uid;
	grp = getgrgid(gid);
	pwd = getpwuid(uid);
	list->links = stats.st_nlink;
	list->owner = pwd->pw_name;
	list->group = grp->gr_name;
	list->size = stats.st_size;
	list->last_change = stock_ctime(stats);
	list->right = (char*)malloc(sizeof(char) * 9 + 1);
	i_right = otoi(stats.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	list->right = assig_right(assig_right(assig_right(list->right, \
		 i_right / 100), i_right / 10 % 10), i_right % 10);
	ft_init_size(ft_strlen(ft_itoa(list->links)), e, "links");
	ft_init_size(ft_strlen(list->owner), e, "owner");
	ft_init_size(ft_strlen(list->group), e, "group");
	ft_init_size(ft_strlen(ft_itoa(list->size)), e, "size");
}

void					add_all_data(t_elem **begin, t_env *e)
{
	struct stat			*stats;
	t_elem				*list;

	stats = malloc(sizeof(struct stat));
	list = *begin;
	while (list->next != NULL)
	{
		list = list->next;
		stat_lstat(stats, e, list);
		get_all(list, *stats, e);
	}
	free(stats);
}
