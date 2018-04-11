/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:19:51 by anhuang           #+#    #+#             */
/*   Updated: 2018/04/11 11:17:15 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

typedef struct	s_data
{
	int				stat;
	char			*name;
	int				x;
	int				y;
	struct s_data	*next;
}				t_data;

typedef struct	s_link
{
	char			*a;
	char			*b;
	struct s_link	*next;
}				t_link;

typedef struct	s_path
{
	char			*str;
	struct s_path	*next;
	struct s_path	*path;
}				t_path;

typedef struct	s_way
{
	char			*str;
	struct s_way	*forb;
	struct s_way	*next;
}				t_way;

typedef struct	s_p
{
	char			*start;
	char			*end;
}				t_p;

void			ft_clean(t_way *way);
void			ft_freecpy(t_way *old);
void			ft_clean2(t_path *way);
void			ft_freecpy2(t_way *old);
void			ft_freend(t_way *way);

int				is_link(char *str, t_link **link);
int				is_data(char *str, t_data **data, int *stat);

void			ft_data_clear(t_data *data, t_link *link);
void			ft_affichage(t_way *way);
long			ft_atol(char *str);
void			ft_error(char *str);

void			ft_go(t_data *data, t_link **link, long ant);
int				ft_start(t_data *data, char *str, int *stat);
int				ft_end(t_data *data, char *str, int *stat);
int				ft_double_rooms(t_data *data, char *str);
int				ft_path(t_link **link, t_path **path, t_p *p);

#endif
