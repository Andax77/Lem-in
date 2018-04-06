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

int			ft_end_way(t_way *way, t_p *p)
{
	while (way->next)
		way = way->next;
	if (ft_strcmp(way->str, p->end) == 0)
		return (0);
	return (1);
}

void		ft_clean(t_way *way)
{
	t_way *tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp->str);
		free(tmp);
	}
}

void		ft_structcpy(t_way *way, t_way **new)
{
	t_way	*tmp;

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
		ft_strcpy(tmp->next->str, way->next->str);
		way = way->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
}
//a free le new avec ses new->str seulement

int			noforb(t_way *way, t_link *link)
{
	while (way->forb)
	{
		if (ft_strcmp(way->forb->str, link->a) == 0 ||
			ft_strcmp(way->forb->str, link->b) == 0)
			return (0);
		way->forb = way->forb->next;
	}
	return (1);
}

static int	ft_check_passed2(t_way **tmp, t_link *link, t_way *new)
{
	while (new)
	{
		if (ft_strcmp(link->a, new->str) == 0)
			return (0);
		new = new->next;
	}
	if (!((*tmp)->next = malloc(sizeof(t_way))))
		ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
	if (!((*tmp)->next->str = malloc(sizeof(char) * ft_strlen(link->a) + 1)))
		ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
	(*tmp)->next->str = ft_strcpy((*tmp)->next->str, link->a);
	(*tmp)->next->next = NULL;
	return (1);
}

static int	ft_check_passed(t_link *link, t_way **way, t_way *new)
{
	t_way	*tmp;

	tmp = *way;
	while (tmp && tmp->next)
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
		if (!(tmp->next->str = malloc(sizeof(char) * ft_strlen(link->b) + 1)))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		tmp->next->str = ft_strcpy(tmp->next->str, link->b);
		tmp->next->next = NULL;
	}
	else if (ft_strcmp(link->b, tmp->str) == 0 && noforb(*way, link))
		return (ft_check_passed2(&tmp, link, new));
	else
		return (0);
	return (1);
}

static int	ft_size_way(t_way *way)
{
	int		i;

	i = 0;
	if (!way)
		return (-1);
	while (way)
	{
		way = way->next;
		i++;
	}
	return (i);
}

char		*get_name(t_way *way, int nb)
{
	if (nb == -1)
	{
		while (way->next)
			way = way->next;
		return (way->str);
	}
	else if (nb == -2)
	{
		while (way->next->next)
			way = way->next;
		return (way->str);
	}
	while (nb-- && way)
		way = way->next;
	return (way->str);
}

int		no_issue(t_way *way, t_link *link)
{
	t_way	*forb;

	forb = way;
	while (way->next)
		way = way->next;
	while (link)
	{
		if (ft_strcmp(link->a, way->str) == 0 || !noforb(forb, link) ||
			ft_strcmp(link->b, way->str) == 0)
			return (0);
		link = link->next;
	}
	return (1);
}

int		ft_new(t_way **way, t_way **new, t_p *p, t_link *link)
{
	t_way	*tmp;

	tmp = *way;
	if (!ft_end_way(*way, p) && (ft_size_way(*way) > ft_size_way(*new)))
	{
		printf("Way %d > new %d\n", ft_size_way(*way), ft_size_way(*new));
		ft_structcpy(*way, new);
		return (1);
	}
	if (!ft_end_way(*way, p) || no_issue(*way, link))
	{
		while (tmp->forb)
			tmp->forb = tmp->forb->next;
		if (!(tmp->forb = malloc(sizeof(t_way))) ||
			!(tmp->forb->str =
				malloc(sizeof(char) * ft_strlen(get_name(*way, -2)) + 1)))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		ft_strcpy(tmp->forb->str, get_name(tmp, -1));
		tmp->forb->next = NULL;
		printf("FORBIDDEN %s\n", tmp->forb->str);
	}
	return (0);
}
//a free dans le way->forb

void		ft_freend(t_way *way)
{
	t_way	*tmp;

	tmp = way;
	while (tmp->next->next)
		tmp = tmp->next;
	while (way->next)
		way = way->next;
	free(way->str);
	free(way);
	tmp->next = NULL;
}

void		ft_recur(t_link *link, t_way **way, t_p *p, t_way **new)
{
	t_way	*tmp;
	t_link	*ori;

	ori = link;
	tmp = *way;
	while (link)
	{
		if (ft_check_passed(link, way, tmp))
			ft_recur(ori, way, p, new);
		link = link->next;
		if (ft_new(way, new, p, link))
			link = ori;

	}
	if (link == NULL && (!ft_end_way(*way, p) || no_issue(*way, link)))
	{
		ft_freend(*way);
		// ft_affichage(*way);
	}
	if (no_issue(*way, link) && !(*way)->next->next)
		return ;
}

int			ft_path(t_data **data, t_link **link, t_path **path, t_p *p)
{
	t_way	*way;
	t_way	*new;

	if (!(way = malloc(sizeof(t_way))))
		ft_error("Malloc error -> ft_path -> ft_algo.c\n");
	if (!(way->str = malloc(sizeof(char*) * ft_strlen(p->start) + 1)))
		ft_error("Malloc error -> ft_path -> ft_algo.c\n");
	way->str = ft_strcpy(way->str, p->start);
	way->next = NULL;
	way->forb = NULL;
	new = NULL;
	ft_recur(*link, &way, p, &new);
	printf("Coucou\n" );
	ft_affichage(new);
	// ft_affichage(way);
	(void)data;
	//Ajout le way dans Path
	ft_clean(way);
	ft_clean(new);
	return (*path ? 1 : 0);
}
