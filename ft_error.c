/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 16:29:50 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 01:00:54 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(int err, char c, char *str, int exit_check)
{
	if (err == 0)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putendl("\nusage: ls [-Ralrt1] [file ...]");
	}
	else if (err == 1)
	{
		ft_putstr("ls: ");
		ft_putstr(str);
		ft_putendl(": No such file or directory");
	}
	if (exit_check == 1)
		exit(0);
}