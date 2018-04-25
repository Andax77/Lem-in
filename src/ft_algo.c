/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:28:19 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/28 11:28:19 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_structcpy(t_way *way, t_way **new)
{
	t_way	*tmp;

	ft_freecpy(*new);
	// printf("NANAAAAN\n");
	// ft_affichage(way);
	if (!(tmp = malloc(sizeof(t_way))) ||
		!(tmp->str = malloc(sizeof(char) * ft_strlen(way->str) + 1)))
		ft_error("Malloc error -> ft_structcpy -> ft_algo.c\n");
	*new = tmp;
	ft_strcpy(tmp->str, way->str);
	while (way->next)
	{
		if (!(tmp->next = malloc(sizeof(t_way))) ||
			!(tmp->next->str = malloc(sizeof(char) * ft_strlen(way->str) + 1)))
			ft_error("Malloc error -> ft_structcpy -> ft_algo.c\n");
		tmp->next->str = ft_strcpy(tmp->next->str, way->next->str);
		way = way->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (1);
}

static int	ft_new(t_way **way, t_way **new, t_link *link, t_p *p)
{
	t_way	*tmp;
	t_way	*tmp2;

	tmp = *way;
	tmp2 = tmp;
	if ((*way)->next && (no_issue(*way, link) || ft_end_way(*way, p)))
	{
		// ft_affichage(*way);
		if (ft_end_way(*way, p) && (ft_size_way(*way) < ft_size_way(*new) ||
				!(*new)))
			ft_structcpy(*way, new);
		while (tmp->next->next)
			tmp = tmp->next;
		// ft_printf("Malloc salle %s\n", tmp->str);
		while (tmp->forb)
			tmp = tmp->forb;
		if (!(tmp->forb = malloc(sizeof(t_way))) ||
			!(tmp->forb->str =
				malloc(sizeof(char) * ft_strlen(get_name(*way, -2)) + 1)))
			ft_error("Malloc error -> ft_new -> ft_algo.c\n");
		tmp->forb->str = ft_strcpy(tmp->forb->str, get_name(tmp2, -1));
		// ft_printf("FORBIDDEN %s->%s\n", tmp->str, tmp->forb->str);
		tmp = tmp->forb;
		ft_freend(tmp2);
		tmp->next = NULL;
		tmp->forb = NULL;
		// ft_affichage(*way);
	}
	return (0);
}

void		ft_recur(t_link *link, t_way **way, t_p *p, t_way **new)
{
	t_way	*tmp;
	t_link	*ori;

	ori = link;
	tmp = *way;
	while (link && ft_end_way(*way, p) == 0)
	{
		if (ft_check_passed(link, way, tmp))
			ft_recur(ori, way, p, new);
		link = link->next;
		if (ft_new(way, new, link, p))
			link = ori;
	}
	// printf("Je sors deja\n");
	if ((*way)->next && (ft_end_way(*way, p) || no_issue(*way, ori)))
	{
		// ft_affichage(*way);
		ft_new(way, new, link, p);
	}
}

int			ft_path(t_link **link, t_path **path, t_p *p)
{
	t_way	*way;
	t_way	*add;

	if (!(way = malloc(sizeof(t_way))) ||
	!(way->str = malloc(sizeof(char*) * ft_strlen(p->start) + 1)))
		ft_error("Malloc error -> ft_path -> ft_algo.c\n");
	way->str = ft_strcpy(way->str, p->start);
	way->next = NULL;
	way->forb = NULL;
	add = NULL;
	ft_recur(*link, &way, p, &add);
	if (!add)
		return (ft_freend(way) ? 0 : 1);
	printf("New end :\n");
	ft_affichage(add);
	if (!(*path))
		ft_add_path(add, path, p);
	else
		ft_add_path2(add, path, p);
	ft_rm_way(link, add);
	// printf("Ici JE SORS WAAH\n");
	ft_clean(add);
	// ft_affichage(way);
	ft_freend(way);
	return (*path ? 1 : 0);
}
