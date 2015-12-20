/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 06:40:49 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/24 07:15:53 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_diff(t_env *e, t_elem *list)
{
	char		*tmp;

	tmp = list->next->data;
	list->next->data = list->data;
	list->data = tmp;
	e->boolean = 1;
//	printf("SWAP = '%s' ET '%s'\n", list->data, list->next->data);
}

// static void		sort_equ(t_env *e, t_elem *list, struct stat *stt, \
// 												struct stat *sttn)
// {
// 	int			i;

// 	i = 0;
// 	while (list->data[i] && list->next->data[i] && \
// 			list->data[i] == list->next->data[i])
// 		i++;
// 	if ((S_ISREG(stt->st_mode)) && (S_ISDIR(sttn->st_mode)))
// 		sort_diff(e, list);
// 	else if ((stt->st_mode & S_IFMT) \
// 			&& S_ISDIR(stt->st_mode) && (S_ISDIR(sttn->st_mode)) \
// 			&& !(ft_strcmp(list->data, ".")) \
// 			&& !(ft_strcmp(list->next->data, "..")))
// 		sort_diff(e, list);
// 	else if (((list->data[i] > list->next->data[i])) \
// 			&& S_ISREG(stt->st_mode) && (S_ISREG(sttn->st_mode)))
// 		sort_diff(e, list);
// 	else if (((list->data[i] > list->next->data[i])) \
// 			&& (S_ISDIR(stt->st_mode)) && (S_ISDIR(sttn->st_mode)) \
// 			&& !(!ft_strcmp(list->data, "..") \
// 			&& !ft_strcmp(list->next->data, ".")))
// 		sort_diff(e, list);
// }


static void		sort_equ(t_env *e, t_elem *list)
{
	int				i;

	i = 0;
	while (list->data[i] && list->next->data[i] && \
			list->data[i] == list->next->data[i])
		i++;
	if (list->data[i] > list->next->data[i])
		sort_diff(e, list);
}



static void		assign_path(t_env *e, t_elem *list,\
							 struct stat *stt, struct stat *sttn)
{
	char		currentPath[FILENAME_MAX];
	char		currentPathn[FILENAME_MAX];

	e->boolean = 0;
	while (list && list->next != NULL)
	{
		if (list->data && list->next->data)
		{
			getcwd(currentPath, FILENAME_MAX);
			strcat(currentPath, "/");
			strcat(currentPath, e->targets[e->i]);
			strcat(currentPath, "/");
			strcat(currentPath, list->data);
			stat(currentPath, stt);
			getcwd(currentPathn, FILENAME_MAX);
			strcat(currentPathn, "/");
			strcat(currentPathn, e->targets[e->i]);
			strcat(currentPathn, "/");
			strcat(currentPathn, list->next->data);
			stat(currentPathn, sttn);
			if (stt->st_mtime == sttn->st_mtime)
				sort_equ(e, list);
				// sort_equ(e, list, stt, sttn);
			else if (stt->st_mtime < sttn->st_mtime)
				sort_diff(e, list);
		}
		list = list->next;
	}
}

void		 	ft_date_sort(t_env *e, t_elem *list)
{
	t_elem		*begin;
	struct stat	*stt;
	struct stat	*sttn;

	stt = malloc(sizeof(struct stat));
	sttn = malloc(sizeof(struct stat));
	begin = list;
	while (e->boolean == 1)
	{
		assign_path(e, list, stt, sttn);
		list = begin;
	}
}
