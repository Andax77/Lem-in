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
	if (ft_strcmp(str, "##start") == 0 && (*stat = 1))
		return (0);
	else if (ft_strcmp(str, "##end") == 0 && (*stat = 2))
		return (0);
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
	return (1);
}

static char		**ft_tabcpy(char **old, int size, char *add)
{
	char		**new;
	int			i;

	if (!(i = 0) && old == NULL)
	{
		if (!(new = malloc(sizeof(char*) * (size + 1))) ||
			!(new[i] = malloc(sizeof(char) * ft_strlen(add) + 1)))
			ft_error("Malloc error Array -> ft_data-> lem-in.c\n");
		return (ft_strcpy(new[i], add) ? new : new);
	}
	if (!(new = malloc(sizeof(char*) * (size + 1))))
		ft_error("Malloc error Array -> ft_data-> lem-in.c\n");
	while (i != size)
	{
		if (!(new[i] = malloc(sizeof(char) * ft_strlen(old[i]) + 1)))
			ft_error("Malloc error Array -> ft_data-> lem-in.c\n");
		ft_strcpy(new[i], old[i]) && i++;
	}
	if (!(new[i] = malloc(sizeof(char) * ft_strlen(add) + 1)))
		ft_error("Malloc error Array -> ft_data-> lem-in.c\n");
	ft_strcpy(new[i], add) && !(i = 0);
	while (i != size)
		free(old[i++]);
	free(old);
	return (new);
}

static void		ft_display(char **ptr, int i, int size)
{
	while (i != size)
	{
		ft_printf("%s\n", ptr[i]);
		free(ptr[i++]);
	}
	free(ptr);
}

static long		ft_data(t_data **data, t_link **link, long ant)
{
	char		*arg;
	int			ret;
	int			stat;
	int			i;
	char		**ptr;

	i = 0;
	stat = 0;
	ptr = NULL;
	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		if (ant == 0)
			ant = ft_atol(arg);
		else if (get_data(data, link, arg, &stat))
			break ;
		ptr = ft_tabcpy(ptr, i, arg);
		free(arg);
		i++;
	}
	free(arg);
	ft_display(ptr, 0, i);
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
	ft_go(data, &link, ant);
	ft_data_clear(data, link);
	return (0);
}
