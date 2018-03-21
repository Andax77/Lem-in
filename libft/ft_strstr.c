/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:31:10 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 11:46:16 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int u;

	u = 0;
	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		u = 0;
		while (needle[u] == haystack[i + u])
		{
			u++;
			if (needle[u] == '\0')
				return (&((char*)haystack)[i]);
		}
		i++;
	}
	return (0);
}
