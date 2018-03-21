/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_let.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:07:10 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/16 10:32:36 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_let(char *str, int i, char c)
{
	int		letter;

	letter = 1;
	if (!str[i])
		return (0);
	while (str[i] != c && str[i] != '\0')
	{
		letter++;
		i++;
	}
	return (letter);
}
