/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:19:51 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/15 10:19:57 by anhuang          ###   ########.fr       */
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
	char			*path;
	struct s_path	*next;
}

typedef struct	s_way
{

	struct s_path	*path;
	struct s_way	*next;
}				t_way;

int				is_link(char *str, t_link **link);
int				is_data(char *str, t_data **data, int *stat);
void			ft_data_clear(t_data *data, t_link *link);
long			ft_atol(char *str);
void			ft_go(t_data *data, t_link *link, long ant);
void			ft_error(char *str);
int				ft_start(t_data *data, char *str, int *stat);
int				ft_end(t_data *data, char *str, int *stat);
int				ft_double_rooms(t_data *data, char *str);
void			ft_all_way(t_data **data, t_link **link, long *ant);

#endif
