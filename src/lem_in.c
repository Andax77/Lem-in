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

static void		get_data(t_data **data, t_link **link, char *str)
{
	if (ft_strcmp(str, "##start") == 0)
		(*data)->stat = 1;
	else if (ft_strcmp(str, "##end") == 0)
		(*data)->stat = 2;
	// else if (str[0] == '#' && str[1] == '#')
	// else if (!ft_strchr(str, ' ') && is_link(str, link))
	else if (!ft_strchr(str, '-') && is_data(str, data))
		return ;

}

static long		ft_data(t_data **data, t_link **link, long ant)
{
	char		*arg;
	int			ret;

	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		get_data(data, link, arg);
		ant == 0 ? ant = get_long(arg) : ant;
		free(arg);
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

	(void)argv;
	(void)argc;
	ant = ft_data(&data, &link, 0);

	return (0);
}
