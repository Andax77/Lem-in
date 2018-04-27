#include "lem_in.h"

static void ant_display2(t_path *path)
{
	t_path	*tmp;
	int		b;

	b = 0;
	while (path)
	{
		tmp = path->next;
		while (tmp->pos != 0)
		{
			if (b > 0)
				ft_printf(" L%ld-%s", tmp->pos, tmp->str);
			else if (b == 0 && ++b)
				ft_printf("L%ld-%s", tmp->pos, tmp->str);
			tmp = tmp->next;
		}
		path = path->path;
	}
	ft_putchar('\n');
}

// static void ant_display3(t_path *path)
// {
//
// }

void        ant_display(t_path *path, long ant, long c)
{
	long	i;
	t_path	*tmp;
	t_path	*tmp2;
	long	a;
	long	b;

	c = 0;
	i = 0;
	a = ant;
	while (a > 0)
	{
		tmp = path;
		while (tmp)
		{
			tmp2 = tmp->next;
			b = tmp->pos;
			while (tmp2->next->next)
			{
				tmp2->pos = b;
				b = tmp2->next->pos;
				tmp2->next->pos = tmp2->pos;
				tmp2 = tmp2->next;
				if (!tmp2->next->next && tmp->pos > 0)
			}
			++i;
			ant--;
			if (ant >= 0)
				tmp->next->pos = i;
			else
				tmp->next->pos = 0;
			tmp = tmp->path;
		}
		ant_display2(path);
	}
}
