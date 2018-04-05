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

void ft_affichage(t_way *way)
{
	while (way)
	{
		printf("%s\n",way->str);
		way = way->next;
	}
}

int ft_end_way(t_way *way, t_p *p)
{
	while (way->next)
		way = way->next;
	if (ft_strcmp(way->str, p->end) == 0)
		return (0);
	return (1);
}

void ft_clean(t_way *way)
{
	t_way *tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp->str);
		free(tmp);
	}
	free(way);
}

static int	ft_check_passed2(t_link *link, t_way **way, t_way *new)
{
	t_way	*tmp;

	tmp = *way;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (ft_strcmp(link->a, tmp->str) == 0)
	{
		while (new)
		{
			if (ft_strcmp(link->b, new->str) == 0)
				return (0);
			new = new->next;
		}
		if (!(tmp->next = malloc(sizeof(t_way*))))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		if (!(tmp->next->str = malloc(sizeof(char) * ft_strlen(link->b))))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		ft_strcpy(tmp->next->str, link->b);
		tmp->next->next = NULL;
	}
	else if (ft_strcmp(link->b, tmp->str) == 0)
	{
		while (new)
		{
			if (ft_strcmp(link->a, new->str) == 0)
				return (0);
			new = new->next;
		}
		if (!(tmp->next = malloc(sizeof(t_way*))))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		if (!(tmp->next->str = malloc(sizeof(char) * ft_strlen(link->a))))
			ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
		ft_strcpy(tmp->next->str, link->a);
		tmp->next->next = NULL;
	}
	else
		return (0);
	return (1);
}

// static int	ft_size_way(t_way *way)
// {
// 	int		i;
//
// 	i = 0;
// 	while (way)
// 	{
// 		way = way->next;
// 		i++;
// 	}
// 	return (i);
// }
//
// static void	ft_check_passed(t_link *link, t_way *way)
// {
// 	t_way	*tmp;
//
// 	(void)link;
// 	tmp = way;
// }

void		ft_recur(t_link *link, t_way **way, t_p *p)
{
	// t_way	*new;
	t_way	*tmp;

	tmp = *way;
	// if (!(new = malloc(sizeof(t_way*))))
	// 	ft_error("Malloc error -> ft_recur -> ft_algo.c\n");
	while (link && ft_end_way(*way, p))
	{
		if (ft_check_passed2(link, way, tmp))
			ft_recur(link, way, p);
		link = link->next;
	}

	// if (ft_size_way(new) > ft_size_way(way))
	// 	way = new;
	// while (new)
	// {
	// 	tmp = new;
	// 	free(tmp);
	// 	new = new->next;
	// }
	// free(new);
}

int			ft_path(t_data **data, t_link **link, t_path **path, t_p *p)
{
	t_way	*way;
	t_way	*tmp;

	printf("Start %s End %s\n", p->start, p->end);
	if (!(way = malloc(sizeof(t_way))))
		ft_error("Malloc error -> ft_path -> ft_algo.c\n");
	if (!(way->str = malloc(sizeof(char*) * ft_strlen(p->start))))
		ft_error("Malloc error -> ft_path -> ft_algo.c\n");
	ft_strcpy(way->str, p->start);
	way->next = NULL;
	tmp = way;
	ft_recur(*link, &way, p);

	ft_affichage(way);
	(void)data;
	ft_clean(way);
	return (*path ? 1 : 0);
}
