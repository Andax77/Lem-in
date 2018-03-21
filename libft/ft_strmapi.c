/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:13:15 by anhuang           #+#    #+#             */
/*   Updated: 2017/11/21 16:45:06 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	int				i;
	unsigned int	a;

	a = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(a++, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
