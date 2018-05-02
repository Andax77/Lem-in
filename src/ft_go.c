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
		data = data->next;
	}
	if (error < 2)
		return (1);
	return (0);
}

static char	*ft_get(t_data *data, int stat)
{
	while (data->stat != stat)
		data = data->next;
	return (data->name);
}

void		ft_clear_path(t_path *path)
{
	t_path	*tmp;
	t_path	*tmp2;

	while (path)
	{
		tmp = path;
		path = path->path;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
				// printf("free : %s\n",tmp2->str);
			free(tmp2->str);
			free(tmp2);
		}
	}
}

void		ft_go(t_data *data, t_link **link, long ant)
{
	t_path	*path;
	t_p		*p;

	if (!(p = malloc(sizeof(t_p) + 1)))
		ft_error("Malloc error -> ft_go -> ft_go.c\n");
	path = NULL;
	if (ft_checker(data, *link))
		ft_error("ERROR\n");
	p->start = ft_get(data, 1);
	p->end = ft_get(data, 2);
	if (ft_go1(data, *link))
		ft_path(link, &path, p);
	else
		while (ft_path(link, &path, p))
			ft_printf("Ant ? %ld\n\n\n", ant);
	free(p);
	if (!path)
		ft_error("ERROR\n");
	//AFFICHER LE PARSE :)
	ant_display(path, ant);
	ft_clear_path(path);
}
