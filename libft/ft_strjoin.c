/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:24:14 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/21 16:45:55 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (s1)
		ft_strcpy(ptr, s1);
	if (s2)
		ft_strcat(ptr, s2);
	return (ptr);
}
