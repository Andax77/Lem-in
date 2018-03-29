/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:59:33 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/29 15:59:34 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_start(t_data *data, char *str, int *stat)
{
	char	**ptr;
	int		i;

	if (!(i = 0) && *stat != 1)
		return (0);
	while (data)
	{
		if (data->stat == *stat)
		{
			ptr = ft_strsplit(str, ' ');
			free(data->name);
			if (!(data->name = malloc(sizeof(char) * ft_strlen(str) + 1)))
				ft_error("Malloc error data.name ->ft_start-> ft_start_end.c");
			ft_strcpy(data->name, ptr[0]);
			data->y = ft_atoi(ptr[1]);
			data->x = ft_atoi(ptr[2]);
			while (ptr[i])
				free(ptr[i++]);
			free(ptr);
			*stat = 0;
			return (1);
		}
		data = data->next;
	}
	return (0);
}

int			ft_end(t_data *data, char *str, int *stat)
{
	char	**ptr;
	int		i;

	if (!(i = 0) && *stat != 2)
		return (0);
	while (data)
	{
		if (data->stat == *stat)
		{
			ptr = ft_strsplit(str, ' ');
			free(data->name);
			if (!(data->name = malloc(sizeof(char) * ft_strlen(str) + 1)))
				ft_error("Malloc error data.name ->ft_start-> ft_start_end.c");
			ft_strcpy(data->name, ptr[0]);
			data->y = ft_atol(ptr[1]);
			data->x = ft_atol(ptr[2]);
			while (ptr[i])
				free(ptr[i++]);
			free(ptr);
			*stat = 0;
			return (1);
		}
		data = data->next;
	}
	return (0);
}

int			ft_double_rooms(t_data *data, char *str)
{
	char	**ptr;
	int		i;

	while (data)
	{
		i = 0;
		ptr = ft_strsplit(str, ' ');
		if (ft_strcmp(data->name, ptr[0]) == 0)
			ft_error("Error Double rooms\n");
		while (ptr[i])
			free(ptr[i++]);
		free(ptr);
		data = data->next;
	}
	return (0);
}
