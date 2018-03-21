/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:55:10 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/15 17:04:29 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char *s, char c)
{
	int		counter;
	int		i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c || s[i] == '\0')
		{
			if (s[i] == '\0')
				return (counter);
			i++;
		}
		counter++;
		while (!(s[i] == c) && s[i] != '\0')
			i++;
	}
	return (counter);
}
