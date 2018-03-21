/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:25:11 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/16 13:29:44 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (void*)malloc(size)))
		return (NULL);
	while (i < size)
		((char*)ptr)[i++] = 0;
	return (ptr);
}
