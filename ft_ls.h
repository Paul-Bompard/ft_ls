/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbompard <pbompard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 02:28:48 by pbompard          #+#    #+#             */
/*   Updated: 2015/11/21 06:52:07 by pbompard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define L_FLAG 	0b00000001
# define A_FLAG 	0b00000010
# define R_FLAG 	0b00000100
# define UR_FLAG 	0b00001000
# define T_FLAG 	0b00010000

// #define F_FLAG 0b00100000
// #define G_FLAG 0b01000000

# include "libft/includes/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>

# include <grp.h>
# include <pwd.h>

# include <stdio.h>

typedef struct		s_elem
{
	struct s_elem	*next;

	char			type;
	char			*right;
	unsigned int	links;
	char			*owner;
	char			*group;
	unsigned int	size;
	char			*last_change;
	char			*data;
	char			mode_link;
}					t_elem;

typedef struct		s_env
{
	int				ac;
	char			**av;
	char			flags;
	char			err_flags;
	char			*pur_flags;
	char			**targets;
	int				boolean;
	int				i;
	int				nb_path;
	int				len_links;
	int				len_owner;
	int				len_group;
	int				len_size;
}					t_env;

// typedef struct		s_list
// {
// 	struct s_list	*next;
// 	void			*data;
// }					t_list;

t_elem				*create_elem(char *data);
t_elem				*add_end(t_elem **begin_list, char *data);

t_elem				*add_begin(t_elem **begin_list, void *data);
void				option_un(void);
void				option_a(void);
void				ft_error(int err, char c, char *str, int exit_check);
void				binary_flag(t_env *e);
void	 			ft_sort(t_env *e, t_elem *begin);
void				flag_extract(t_env *e);
void				ft_init(t_env *e, int argc, char **argv);
void	 			ft_rev_sort(t_env *e, t_elem *list);
void				add_all_data(t_elem **begin, t_env *e);
void	 			ft_date_sort(t_env *e, t_elem *list);
void	 			ft_rev_date_sort(t_env *e, t_elem *list);
void				clear_list(t_elem **begin_list);
t_elem				*create_all_elem(t_env *e, char *target);
int					otoi(unsigned int n);
void				sort_path(t_env *e);
struct stat			*ft_stats(char *str, t_env *e, t_elem *list, struct stat *stats);
void				stat_lstat(struct stat *stats, t_env *e, t_elem *list);
void				ft_init_size(int i, t_env *e, char *str);
void				ft_indent(char *str, t_env *e, char *corresp);
void				recursive(t_env *e, t_elem *list, char *target);
void				what_flags(t_env *e, t_elem *list);


#endif