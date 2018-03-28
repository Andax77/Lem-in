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

static void		get_data(t_data **data, t_link **link, char *str, int *stat)
{
	if (ft_strcmp(str, "##start") == 0)
		*stat = 1;
	else if (ft_strcmp(str, "##end") == 0)
		*stat = 2;
	else if (str[0] == '#' && str[1] != '#')
		return ;
	else if (!ft_strchr(str, ' ') && ft_strchr(str, '-') && is_link(str, link))
		return ;
	else if (ft_strchr(str, ' ') && is_data(str, data, stat))
		return ;
		// printf("Stat :%d\n",(*data)->stat );

	return ;
}

static long		ft_data(t_data **data, t_link **link, long ant)
{
	char		*arg;
	int			ret;
	int			stat;

	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		ant == 0 ? ant = ft_atol(arg) : ant;
		get_data(data, link, arg, &stat);
		ft_printf("%s\n", arg);
		free(arg);
	}
	if (ret == -1)
		perror("Error\n");
	return (ant);
}

int				main(int argc, char const *argv[])
{
	t_data	*data;
	t_link	*link;
	long	ant;

	data = NULL;
	link = NULL;
	(void)argv;
	(void)argc;
	ant = ft_data(&data, &link, 0);
	ft_go(data, link, ant);
	ft_data_clear(data, link);
	return (0);
}
