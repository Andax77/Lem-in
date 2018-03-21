/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:19:38 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 12:59:34 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *src, int c)
{
	if (!(ft_strchr(src, c)))
		return (NULL);
	while (*src)
		src++;
	while (*src != c)
		src--;
	return ((char*)src);
}
