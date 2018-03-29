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

int			ft_start(t_data **data, char *str, int *stat)
{
	t_data	*tmp;
	char	**ptr;
	int		i;

	tmp = *data;
	if (!(i = 0) && *stat != 1)
		return (0);
	while (tmp)
	{
		if (tmp->stat == *stat)
		{
			ptr = ft_strsplit(str, ' ');
			free(tmp->name);
			if (!(tmp->name = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
				ft_error("Malloc error data.name ->ft_start-> ft_start_end.c");
			ft_strcpy(tmp->name, ptr[0]);
			tmp->y = ft_atoi(ptr[1]);
			tmp->x = ft_atoi(ptr[2]);
			while (ptr[i])
				free(ptr[i++]);
			free(ptr);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			ft_end(t_data **data, char *str, int *stat)
{
	t_data	*tmp;
	char	**ptr;
	int		i;

	tmp = *data;
	if (!(i = 0) && *stat != 2)
		return (0);
	while (tmp)
	{
		if (tmp->stat == *stat)
		{
			ptr = ft_strsplit(str, ' ');
			free(tmp->name);
			if (!(tmp->name = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
				ft_error("Malloc error data.name ->ft_start-> ft_start_end.c");
			ft_strcpy(tmp->name, ptr[0]);
			tmp->y = ft_atol(ptr[1]);
			tmp->x = ft_atol(ptr[2]);
			while (ptr[i])
				free(ptr[i++]);
			free(ptr);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
