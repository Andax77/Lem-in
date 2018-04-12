
#include "lem_in.h"

void		ft_clean(t_way *way)
{
	t_way	*tmp;
	// t_way	*tmp2;
	// t_way	*forb;

	while (way)
	{
		tmp = way;
		way = way->next;
		// if (tmp->forb)
		// {
		// 	tmp2 = tmp->forb;
		// 	while (tmp2)
		// 	{
		// 		forb = tmp2;
		// 		tmp2 = tmp2->forb;
		// 		free(forb->str);
		// 		free(forb);
		// 	}
		// }
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

void		ft_clean2(t_path *way)
{
	t_path	*tmp;
	t_path	*tmp2;

	tmp2 = way->path;
	while (tmp2->path)
	{
		tmp = tmp2->path;
		tmp2 = tmp2->path;
		free(tmp->path->str);
		free(tmp->path);
	}
	while (way)
	{
		tmp = way;
		way = way->next;
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
	while (tmp4->forb)
		tmp4 = tmp4->forb;
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
