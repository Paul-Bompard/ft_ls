/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 20:14:40 by pbompard          #+#    #+#             */
/*   Updated: 2015/12/20 20:14:46 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	struct stat		*ft_stats(char *str, t_env *e, t_elem *list,\
**		struct stat *stats)
**	{
**		char		*current_path;
**		current_path = (char *)malloc(sizeof(char) * FILENAME_MAX);
**		if (e->targets[e->i][0] != '/')
**		{
**			getcwd(current_path, FILENAME_MAX);
**			ft_strcat(current_path, "/");
**		}
**		ft_strcat(current_path, e->targets[e->i]);
**		ft_strcat(current_path, "/");
**		if (!(ft_strcmp(str, "now")))
**			ft_strcat(current_path, list->data);
**		else if (!(ft_strcmp(str, "next")))
**			ft_strcat(current_path, list->next->data);
**		stat(current_path, stats);
**		lstat(current_path, stats);
**		return (stats);
**	}
*/

void	ft_stats(char *str, t_env *e, t_elem *list)
{
	char		*current_path;


	current_path = (char *)malloc(sizeof(char) * FILENAME_MAX);
	if (e->targets[e->i][0] != '/')
	{
		getcwd(current_path, FILENAME_MAX);
		ft_strcat(current_path, "/");
	}
	ft_strcat(current_path, e->targets[e->i]);
	ft_strcat(current_path, "/");
	if (!(ft_strcmp(str, "now")))
	{
		ft_strcat(current_path, list->data);
		stat(current_path, e->stt);
		lstat(current_path, e->stt);
	}
	else if (!(ft_strcmp(str, "next")))
	{
		ft_strcat(current_path, list->next->data);
		stat(current_path, e->sttn);
		lstat(current_path, e->sttn);
	}
		// printf("target = %s\n", current_path);

		// printf("target = %s\n", ft_strjoin(ft_strjoin(target, "/"),\
		// 	list->data));



}
