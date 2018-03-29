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
	t_link	*tmp2;
	int		tube;
	char	*start;
	char	*end;

	tube = 0;
	while (data)
	{
		if (data->stat == 1)
			start = data->name;
		else if (data->stat == 2)
			end = data->name;
		data = data->next;
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

static int	ft_checker(t_data *data, t_link *link)
{
	int		error;

	error = 0;
	if (!(data) || !(link))
		return (1);
	while (data)
	{
		if (data->stat == 1 || data->stat == 2)
			error++;
		printf("%d %s %d %d\n",data->stat, data->name, data->y, data->x );
		data = data->next;
	}
	if (error < 2)
		return (1);
	return (0);
}

void		ft_go(t_data *data, t_link *link, long ant)
{
	printf("ant %ld\n",ant );
	if (ft_checker(data, link))
		ft_error("ERROR\n");
	if (ft_go1(data, link))
		printf("BOnjour\n");
	else
		ant++;
		// ft_one_way(
	// else
	// 	ft_all_way(
}
