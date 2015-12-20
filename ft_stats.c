/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:08:21 by pbompard          #+#    #+#             */
/*   Updated: 2015/12/11 01:08:23 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat		*ft_stats(char *str, t_env *e, t_elem *list, \
						struct stat *stats)
{
	char		*currentPath;

	currentPath = (char *)malloc(sizeof(char) * FILENAME_MAX);

	if (e->targets[e->i][0] != '/')
	{
		// ft_bzero(currentPath, FILENAME_MAX);
		getcwd(currentPath, FILENAME_MAX);
		strcat(currentPath, "/");
	}
	strcat(currentPath, e->targets[e->i]);
	strcat(currentPath, "/");
	if (!ft_strcmp(str, "now"))
		strcat(currentPath, list->data);
	else if (!ft_strcmp(str, "next"))
		strcat(currentPath, list->next->data);
	stat(currentPath, stats);
	lstat(currentPath, stats);
		// printf("currentPath = %s\n", currentPath);

	return (stats);
}