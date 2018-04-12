
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
	t_way	*tmp2;
	t_way	*forb;

	while (old)
	{
		tmp = old;
		old = old->next;
		if (tmp->forb)
		{
			tmp2 = tmp->forb;
			while (tmp2)
			{
				forb = tmp2;
				tmp2 = tmp2->forb;
				free(forb->str);
				free(forb);
			}
			tmp->forb = NULL;
		}
		free(tmp->str);
		free(tmp);
	}
}

void		ft_freend(t_way *way)
{
	t_way	*tmp;
	t_way	*tmp2;
	t_way	*tmp3;
	t_way	*tmp4;

	tmp = way;
	tmp4 = way;
	while (tmp->next->next)
		tmp = tmp->next;
	while (way->next)
		way = way->next;
	tmp2 = way->forb;
	while (tmp2)
	{
		tmp3 = tmp2;
		tmp2 = tmp2->forb;
		free(tmp3->str);
		free(tmp3);
	}
	tmp4->forb = NULL;
	free(way->str);
	free(way);
	tmp->next = NULL;
}
