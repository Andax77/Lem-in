
#include "lem_in.h"

void		ft_clean(t_way *way)
{
	t_way	*tmp;

	while (way)
	{
		tmp = way;
		way = way->next;
		free(tmp->str);
		free(tmp);
	}
}

void		ft_freecpy(t_way *old)
{
	t_way	*tmp;

	while (old)
	{
		tmp = old;
		old = old->next;
		free(tmp->str);
		free(tmp);
	}
}

int		ft_freend(t_way *way)
{
	t_way	*tmp2;
	t_way	*tmp3;
	t_way	*tmp4;

	tmp4 = way;
	while (tmp4->next && tmp4->next->next)
		tmp4 = tmp4->next;
	while (way->next)
		way = way->next;
	if (way->forb)
	{
		tmp2 = way->forb;
		while (tmp2)
		{
			// ft_printf("Je freee forb\n" );
			tmp3 = tmp2;
			tmp2 = tmp2->forb;
			// ft_printf("%s\n",tmp3->str);
			free(tmp3->str);
			free(tmp3);
		}
		way->forb = NULL;
	}
	// ft_printf("Je freee way\n%s\n", way->str);
	if (tmp4->next)
		tmp4->next = NULL;
	free(way->str);
	free(way);
	return (1);
}

static void	ft_rm_way2(t_link **init, t_link **link, t_link **link2, int i)
{
	t_link	*tmp;

	tmp = (*init);
	if (i == 0)
	{
		if (!(*init)->next)
			*link = NULL;
		*link = (*init)->next;
		(*link2) = *link;
	}
	else if (!(*init)->next)
		(*link2)->next = NULL;
	else
		(*link2)->next = (*init)->next;
	(*init) = (*init)->next;
	// ft_printf("Link rm %s-%s\n", tmp->a, tmp->b);
	free(tmp->a);
	free(tmp->b);
	free(tmp);
}

void		ft_rm_way(t_link **link, t_way *way)
{
	t_link	*tmp;
	t_link	*init;
	t_link	*link2;
	int		i;

	tmp = *link;
	while (way->next->next && !(i = 0))
	{
		way = way->next;
		link2 = *link;
		init = *link;
		while (init)
		{
			while (init && (ft_strcmp(way->str, init->a) == 0 ||
				ft_strcmp(way->str, init->b) == 0))
				ft_rm_way2(&init, link, &link2, i);
			if (init && ++i)
			{
				if (!init->next && link2->next)
					link2->next->next = NULL;
				else
					link2 = (i == 1 ? link2 : link2->next);
				init = init->next;
			}
		}
	}
}
