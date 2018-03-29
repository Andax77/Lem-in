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

static int		get_data(t_data **data, t_link **link, char *str, int *stat)
{
	if (ft_strcmp(str, "##start") == 0)
		*stat = 1;
	else if (ft_strcmp(str, "##end") == 0)
		*stat = 2;
	else if (str[0] == '#' && str[1] != '#')
		return (0);
	else if (!ft_strchr(str, ' ') && ft_strchr(str, '-') && is_link(str, link))
		return (0);
	else if (ft_strchr(str, ' ') && is_data(str, data, stat))
		return (0);
	else if (str[0] == '\0')
		return (1);
	else if (ft_strchr(str, ' ') && ft_strchr(str, '-'))
		return (1);
	return (0);
}

static long		ft_data(t_data **data, t_link **link, long ant)
{
	char		*arg;
	int			ret;
	int			stat;
	int			i;

	i = 0;
	stat = 0;
	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		if (ant == 0)
			ant = ft_atol(arg);
		else if (get_data(data, link, arg, &stat))
			continue ;
	// ft_printf("%s\n", arg);
		free(arg);
		i++;
	}
	free(arg);
	if (ret == -1)
		ft_error("Error\n");
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
