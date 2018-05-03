/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:36:58 by anhuang           #+#    #+#             */
/*   Updated: 2018/05/03 14:36:59 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ant_display2(t_path *path)
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

static void	shift_right(t_path **tmp, long *a, long *i, long *ant)
{
	long	copy;
	long	c;
	t_path	*tmp2;

	while (*tmp)
	{
		tmp2 = (*tmp)->next;
		copy = tmp2->next->pos;
		copy = tmp2->pos;
		tmp2->pos = 0;
		while (tmp2->next)
		{
			if (!tmp2->next->next && tmp2->next->pos > 0)
				(*a)--;
			c = tmp2->next->pos;
			tmp2->next->pos = copy;
			copy = c;
			tmp2 = tmp2->next;
		}
		if (++(*i) && *ant >= 0 && (*ant)--)
			(*tmp)->next->pos = *i;
		else
			(*tmp)->next->pos = 0;
		*tmp = (*tmp)->path;
	}
}

int			ant_display(t_path *path, long ant)
{
	long	i;
	t_path	*tmp;
	long	a;

	i = 0;
	a = ant;
	while (!path->next->next && i - 1 != ant)
		if (i == 0 && ++i)
			ft_printf("L%ld-%s", i++, path->str);
		else
			ft_printf(" L%ld-%s", i++, path->str);
	if (!path->next->next)
		return (ft_printf("\n") ? 1 : 1);
	while (a > 0 && a)
	{
		tmp = path;
		shift_right(&tmp, &a, &i, &ant);
		ant_display2(path);
	}
	return (ft_printf("\0") ? 1 : 1);
}
