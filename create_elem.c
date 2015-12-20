/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:06:26 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/27 23:10:25 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*create_elem(char *data)
{
	t_elem	*newelement;

	newelement = malloc(sizeof(t_elem));
	newelement->data = data;
	newelement->next = NULL;
	return (newelement);
}
