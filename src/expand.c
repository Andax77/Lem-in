/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:34:11 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/28 12:34:12 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_data_clear(t_data *data, t_link *link)
{
	t_data	*tmp;
	t_link	*tmp2;

	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp->name);
		free(tmp);
	}
	while (link)
	{
		ft_printf("Link ?%s\n", link->a);
		tmp2 = link;
		link = link->next;
		free(tmp2->a);
		free(tmp2->b);
		free(tmp2);
	}
}

long		ft_atol(char *str)
{
	int		i;
	long	nbr;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error("Ant WTH ?! -> ft_atol -> lem_in.c\n");
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

void		ft_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(0);
}

void		ft_affichage(t_way *way)
{
	ft_printf("End : ");
	while (way)
	{
		ft_printf("%s-", way->str);
		way = way->next;
	}
	ft_printf("\n");
}
