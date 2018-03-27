/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:15:25 by anhuang           #+#    #+#             */
/*   Updated: 2018/03/26 17:15:26 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_link(char *str, t_link **link)
{
	int		i;
	int		a;
	t_link	*new;

	i = 0;
	a = 0;
	new = *link;
	while (new)
		new = new->next;
	if (!(new = (t_link*)malloc(sizeof(t_link))))
		perror("Malloc error to link-> is_link -> lem_in2.c");
	while (str[i] != '-')
		i++;
	if (!(new->a = (char*)malloc(sizeof(char) * i + 1)))
		perror("Malloc error to new.a -> is_link -> lem_in2.c");
	new->a = ft_strncpy(new->a, str, i);
	while (str[i++])
		a++;
	if (!(new->b = (char*)malloc(sizeof(char) * a + 1)))
		perror("Malloc error to new.b -> is_link -> lem_in2.c");
	new->b = ft_strncpy(new->b, str + i - a, a);
	new->next = NULL;
	if ((*link) == NULL)
		(*link) = new;
	else
		(*link)->next = new;
	return (1);
}

int		is_data(char *str, t_data **data, int stat)
{
	int		i;
	int		a;
	t_data	*new;

	a = 0;
	i = 0;
	new = *data;
	while (new)
		new = new->next;
	if (!(new = (t_data*)malloc(sizeof(t_data))))
		perror("Malloc error to data-> is_data -> lem_in2.c");
	while (str[a + i] != ' ')
		a++;
	if (!(new->name = (char*)malloc(sizeof(char) * a + 1)))
		perror("Malloc error to data.name -> is_data -> lem_in2.c");
	while (str[i] != ' ')
		new->name[a++] = str[i++];
	new->name[a] = '\0';
	while (ft_isdigit(str[++i]))
		new->y = new->x * 10 + str[i] - '0';
	while (ft_isdigit(str[++i]))
		new->x = new->y * 10 + str[i] - '0';
	new->stat = !new->stat ? stat : 0;
	new->next = NULL;
	if (*data == NULL)
		(*data) = new;
	else
		(*data)->next = new;
	return (1);
}
