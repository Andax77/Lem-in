/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:18:51 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/15 10:18:52 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static long		get_long(char *str)
{
	int			i;
	long		nbr;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			perror("Error\n");
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

static void		get_data(t_data **data, t_link **link, char *str, int *stat)
{
	if (ft_strcmp(str, "##start") == 0)
		*stat = 1;
	else if (ft_strcmp(str, "##end") == 0)
		*stat = 2;
	// else if (str[0] == '#' && str[1] == '#')
	else if (str[0] == '#' && str[1] != '#')
		return ;
	else if (!ft_strchr(str, ' ') && ft_strchr(str, '-') && is_link(str, link))
		return ;
	else if (ft_strchr(str, ' ') && is_data(str, data, *stat))
		return ;
	else
		stat = 0;
	return ;

}

static long		ft_data(t_data **data, t_link **link, long ant)
{
	char		*arg;
	int			ret;
	int			stat;

	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		// ft_printf("%s\n",arg );
		ant == 0 ? ant = get_long(arg) : ant;
		get_data(data, link, arg, &stat);
		free(arg);
	}
	while (*data)
	{
		ft_printf("%s %d %d\n", (*data)->name, (*data)->x, (*data)->y);
		(*data = (*data)->next);
	}
	while (*link)
	{
		ft_printf("%s-%s\n", (*link)->a, (*link)->b);
		(*link = (*link)->next);
	}
	if (ret == -1)
		perror("Error\n");
	return (ant);
}

int			main(int argc, char const *argv[])
{
	t_data	*data;
	t_link	*link;
	long	ant;

	data = NULL;
	link = NULL;
	(void)argv;
	(void)argc;
	ant = ft_data(&data, &link, 0);

	return (0);
}
