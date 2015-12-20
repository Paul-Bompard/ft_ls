/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 00:59:54 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/30 10:45:48 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			nb_path(t_env *e)
{
	int			i;

	i = 0;
	// printf("FLAGS : '%s'\n\n", e->pur_flags);
	while (e->targets[i])
	{
		// printf("PATH %d : %s\n", i + 1, e->targets[i]);
		i++;
	}
	e->nb_path = i;
	// printf("\n");
}

static void		current_path(t_env *e)
{
	e->targets = (char **)malloc(sizeof(char*) * 2);
	e->targets[0] = (char *)malloc(sizeof(char) * 2);
	e->targets[0][0] = '.';
	e->targets[0][1] = '\0';
	e->targets[1] = NULL;
}

static int		ft_path_assign(t_env *e, int i, int k)
{
	int			j;

	j = 0;
	if ((opendir(e->av[i])))
	{
		e->targets[k] = (char*)malloc(sizeof(char) * ft_strlen(e->av[i]) + 1);
		while (e->av[i][j])
		{
			e->targets[k][j] = e->av[i][j];
			j++;
		}
		e->targets[k][j] = '\0';
		k++;
	}
	else



// dire si c'est un fichier, un lien symbolique ou autre




		ft_error(1, 0, e->av[i], 0);
		// printf("ls: %s: No such file or directory\n", e->av[i]);
	return (k);
}

static void		path_extract(t_env *e, int i)
{
	int			k;

	if (i + 1 <= e->ac)
	{
		k = 0;
		e->targets = (char**)malloc(sizeof(char*) * e->ac + 1);
		while (i + 1 <= e->ac)
		{
			k = ft_path_assign(e, i, k);
			i++;
		}
		e->targets[k] = NULL;
		sort_path(e);
	}
	else
		current_path(e);
}

void			flag_extract(t_env *e)
{
	int			i;
	int			j;
	int			k;

	i = 1;
	k = 0;
	e->pur_flags = (char*)malloc(sizeof(char) * 1024 + 1);
	while (i + 1 <= e->ac && e->av[i] && e->av[i][0] == '-')
	{
		j = 1;
		while (e->av[i][0] == '-' && ft_isalpha(e->av[i][j]) && e->av[i][j])
		{
			e->pur_flags[k] = e->av[i][j];
			j++;
			k++;
		}
		if (!ft_isalpha(e->av[i][j]) && e->av[i][j] && e->av[i][0] == '-')
			ft_error(0, e->av[i][j], NULL, 1);
		i++;
	}
	e->pur_flags[k] = '\0';
	binary_flag(e);
	path_extract(e, i);
	// printf("%s\n", e->targets[0]);

	nb_path(e);
}
