/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:04:46 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/28 16:04:46 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_go1(t_data *data, t_link *link)
{
	t_data	*tmp;
	t_link	*tmp2;
	int		tube;
	char	*start;
	char	*end;

	tube = 0;
	tmp = data;
	while (tmp)
	{
		if (tmp->stat == 1)
		{
			printf("%s\n", tmp->name);
			start = tmp->name;
		}
		else if (tmp->stat == 2)
			end = tmp->name;
		tmp = tmp->next;
	}
	printf("Start %s\n", start);
	printf("End   %s\n", end);
	tmp2 = link;
	while (tmp2)
	{
		if (ft_strcmp(tmp2->a, start) == 0 || ft_strcmp(tmp2->b, start) == 0)
			tube++;
		tmp2 = tmp2->next;
		if (tube == 2)
			return (0);
	}
	tube = 0;
	tmp2 = link;
	while (tmp2)
	{
		if (ft_strcmp(tmp2->a, end) == 0 || ft_strcmp(tmp2->b, end) == 0)
			tube++;
		tmp2 = tmp2->next;
		if (tube == 2)
			return (0);
	}
	return (1);
}

void		ft_go(t_data *data, t_link *link, long ant)
{
	ant++;
	if (ft_go1(data, link))
		printf("BOnjour\n");
	else
		ant++;
		// ft_one_way(
	// else
	// 	ft_all_way(
}
