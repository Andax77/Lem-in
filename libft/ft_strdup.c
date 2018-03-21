/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:40:47 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/20 16:20:28 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (s[size] != '\0')
		size++;
	if (!(ptr = malloc(sizeof(*s) * (size + 1))))
		return (NULL);
	while (i++ < size)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}
