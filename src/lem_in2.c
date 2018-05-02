/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:15:25 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/26 17:15:26 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			is_link2(char *str, t_link **new)
{
	int				a;
	int				i;

	i = 0;
	a = 0;
	if (!((*new) = (t_link*)malloc(sizeof(t_link) + 1)))
		ft_error("Malloc error to link-> is_link -> lem_in2.c");
	while (str[i] != '-')
		i++;
	if (!((*new)->a = (char*)malloc(sizeof(char) * i + 1)))
		ft_error("Malloc error to new.a -> is_link -> lem_in2.c");
	(*new)->a = ft_strncpy((*new)->a, str, i);
	(*new)->a[i] = '\0';
	while (str[i++])
		a++;
	if (!((*new)->b = (char*)malloc(sizeof(char) * a + 1)))
		ft_error("Malloc error to new.b -> is_link -> lem_in2.c");
	(*new)->b = ft_strncpy((*new)->b, str + i - a, a);
	(*new)->b[a] = '\0';
	(*new)->next = NULL;
}

int					is_link(char *str, t_link **link)
{
	t_link			*new;
	static t_link	*last;
	char			*tmp;
	int				i;
	int				a;

	a = 0;
	i = 0;
	tmp = ft_strdup(str);
	while (tmp[i] && a > 1)
		if (a > 1)
			ft_error("ERROR\n");
		else if (tmp[i++] == '-')
			a++;
	is_link2(str, &new);
	if (last == NULL)
	{
		*link = new;
		last = *link;
	}
	else
	{
		last->next = new;
		last = new;
	}
	free(tmp);
	return (1);
}

static void			is_data2(char *str, t_data **new, int stat)
{
	int				i;
	int				a;
	char			**ptr;

	i = -1;
	a = 0;
	if (!((*new) = (t_data*)malloc(sizeof(t_data))))
		ft_error("Malloc error to data-> is_data -> lem_in2.c");
	ptr = ft_strsplit(str, ' ');
	while (ptr[0][a])
		a++;
	if (!((*new)->name = (char*)malloc(sizeof(char) * a + 1)))
		ft_error("Malloc error to data.name -> is_data -> lem_in2.c");
	while (ptr[0][++i])
		(*new)->name[i] = str[i];
	(*new)->name[i] = '\0';
	(*new)->y = ft_atoi(ptr[1]);
	(*new)->x = ft_atoi(ptr[2]);
	(*new)->stat = stat;
	(*new)->next = NULL;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int					is_data(char *str, t_data **data, int *stat)
{
	t_data			*new;
	static t_data	*last;

	new = *data;
	if (ft_start(*data, str, stat))
		return (1);
	else if (ft_end(*data, str, stat))
		return (1);
	else if (ft_double_rooms(*data, str))
		return (1);
	else
		is_data2(str, &new, *stat);
	if (last == NULL)
	{
		*data = new;
		last = *data;
	}
	else
	{
		last->next = new;
		last = new;
	}
	*stat = 0;
	return (1);
}
