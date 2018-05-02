#include "lem_in.h"

static void ant_display2(t_path *path)
{
	t_path	*tmp;
	int		b;

	b = 0;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if (b > 0 && tmp->pos != 0)
				ft_printf(" L%ld-%s", tmp->pos, tmp->str);
			else if (b == 0 && tmp->pos != 0 && ++b)
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
	long	copy;

	c = 0;
	i = 0;
	a = ant;
	while (a > 0 && a)
	{
		tmp = path;
		while (tmp)
		{
			tmp2 = tmp->next;
			copy = tmp2->next->pos;
			copy = tmp2->pos;
			tmp2->pos = 0;
			while (tmp2->next)
			{
				if (!tmp2->next->next && tmp2->next->pos > 0)
					a--;
				c = tmp2->next->pos;
				tmp2->next->pos = copy;
				copy = c;
				tmp2 = tmp2->next;
			}
			++i;
			if (ant >= 0 && ant--)
				tmp->next->pos = i;
			else
				tmp->next->pos = 0;
			tmp = tmp->path;
		}
		ant_display2(path);
	}
}
