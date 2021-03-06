/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrm_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:36:34 by anhuang           #+#    #+#             */
/*   Updated: 2018/05/03 14:36:35 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_size_way(t_way *way)
{
	int		i;

	i = 0;
	while (way)
	{
		way = way->next;
		i++;
	}
	return (i);
}

int			ft_add_path(t_way *old, t_path **path, t_p *p)
{
	t_path	*tmp;

	if (!(*path = malloc(sizeof(t_path))))
		ft_error("Malloc error -> ft_add_path -> ft_algo.c\n");
	tmp = *path;
	tmp->str = ft_strdup(p->start);
	tmp->path = NULL;
	tmp->pos = 0;
	while (old->next)
	{
		if (!(tmp->next = malloc(sizeof(t_path))))
			ft_error("Malloc error -> ft_add_path -> ft_algo.c\n");
		tmp->next->str = ft_strdup(old->next->str);
		tmp->next->pos = 0;
		old = old->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (1);
}

int			ft_add_path2(t_way *old, t_path **path, t_p *p)
{
	t_path	*tmp;

	tmp = ((*path)->path ? (*path)->path : *path);
	while (tmp->path)
		tmp = tmp->path;
	if (!(tmp->path = malloc(sizeof(t_path))))
		ft_error("Malloc error -> ft_add_path2 -> ft_algo.c\n");
	tmp->path->str = ft_strdup(p->start);
	tmp->path->path = NULL;
	tmp->path->pos = 0;
	tmp = tmp->path;
	while (old && old->next)
	{
		if (!(tmp->next = malloc(sizeof(t_path))))
			ft_error("Malloc error -> ft_add_path2 -> ft_algo.c\n");
		tmp->next->str = ft_strdup(old->next->str);
		tmp->next->pos = 0;
		old = old->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (1);
}

int			ft_check_passed2(t_way **tmp, t_link *link, t_way *new)
{
	while (new)
	{
		if (ft_strcmp(link->a, new->str) == 0)
			return (0);
		new = new->next;
	}
	if (!((*tmp)->next = malloc(sizeof(t_way))))
		ft_error("Malloc error -> ft_check_passed2 -> ft_algo.c\n");
	(*tmp)->next->str = ft_strdup(link->a);
	// ft_printf("Add %s\n",link->a);
	*tmp = (*tmp)->next;
	(*tmp)->next = NULL;
	(*tmp)->forb = NULL;
	return (1);
}

int			ft_check_passed(t_link *link, t_way **way, t_way *new)
{
	t_way	*tmp;

	tmp = *way;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(link->a, tmp->str) == 0 && noforb(*way, link))
	{
		while (new)
		{
			if (ft_strcmp(link->b, new->str) == 0)
				return (0);
			new = new->next;
		}
		if (!(tmp->next = malloc(sizeof(t_way))))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		tmp->next->str = ft_strdup(link->b);
		// ft_printf("Add %s\n",link->b);
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->forb = NULL;
	}
	else if (ft_strcmp(link->b, tmp->str) == 0 && noforb(*way, link))
		return (ft_check_passed2(&tmp, link, new));
	else
		return (0);
	return (1);
}
