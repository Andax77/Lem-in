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
	(void)str;
	(void)link;
	return (1);
}

int		is_data(char *str, t_data **data)
{
	int i;
	int a;

	a = 0;
	i = 0;
	if (!((*data) = (t_data*)malloc(sizeof(t_data))))
		perror("Malloc error to data-> is_data -> lem_in2.c");
	while (str[i] == ' ')
		i++;
	while (str[a + i] != ' ')
		a++;
	if (!(*data)->name = (char*)malloc(sizeof(char * a + 1)))
		perror("Malloc error to data.name -> is_data -> lem_in2.c")
	while (str[i] != ' ' && ++a && ++i)
		(*data)->name[a - 1] = str[i - 1];
	(*data)->name[a] = '\0';
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]) && ++i)
		(*data)->y = (*data)->y * 10 + str[i] - '0';
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]) && ++i)
		(*data)->x = (*data)->x * 10 + str[i] - '0';
	(*data)->next = NULL;
	return (1);
}
