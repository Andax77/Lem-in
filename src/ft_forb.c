#include "lem_in.h"

int			ft_end_way(t_way *way, t_p *p)
{
	while (way->next)
		way = way->next;
	if (ft_strcmp(way->str, p->end) == 0)
		return (1);
	return (0);
}

int			noforb(t_way *way, t_link *link)
{
	t_way	*tmp;

	tmp = way;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->forb)
	{
		tmp = tmp->forb;
		if (ft_strcmp(tmp->str, link->a) == 0 ||
			ft_strcmp(tmp->str, link->b) == 0)
			return (0);
	}
	return (1);
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

int			no_issue(t_way *way, t_link *link)
{
	t_way	*forb;
	t_way	*tmp;

	tmp = way;
	forb = way;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	while (way->next)
		way = way->next;
	while (link)
	{
		if (ft_strcmp(link->a, way->str) == 0 || noforb(forb, link) ||
			ft_strcmp(link->b, way->str) == 0)
			return (0);
		link = link->next;
	}
	// while (link)
	// {
	// 	if ((ft_strcmp(link->a, way->str) == 0 && ft_strcmp(link->b, link->a)) > 0 ||
	// 		(ft_strcmp(link->b, way->str) == 0 && ft_strcmp(link->a, link->b)) > 0
	// 		|| noforb(forb, link))
	// 		return (0);
	// 	link = link->next;
	// }
	return (1);
}

void		ft_forb(t_way *way)
{
	t_way *tmp;

	while (way)
	{
		if (way->forb)
		{
			// ft_printf("Forb %s->", way->str);
			tmp = way->forb;
			while (tmp)
			{
				// ft_printf("%s->", tmp->str);
				tmp = tmp->forb;
			}
			// ft_putchar('\n');
		}
		way = way->next;
	}
}
