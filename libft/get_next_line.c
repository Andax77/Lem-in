/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:23:38 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/15 17:07:08 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char*)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char*)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

static int		ft_line(t_buf *tmp, char **line)
{
	size_t			size_l;
	size_t			size_f;

	size_f = ft_strlen(tmp->s);
	size_l = 0;
	while (tmp->s[size_l] != '\n' && tmp->s[size_l] != '\r' &&
			tmp->s[size_l] != '\0')
		size_l++;
	if (!(*line = malloc(sizeof(**line) * (size_l + 1))))
		return (-1);
	ft_strncpy(*line, tmp->s, size_l);
	(*line)[size_l] = '\0';
	ft_memmove(tmp->s, tmp->s + size_l + 1, size_f - size_l);
	if (!(tmp->s = ft_realloc(tmp->s, size_f - size_l + 1)))
		return (-1);
	tmp->s[size_f - size_l] = '\0';
	return (1);
}

static int		ft_getread(t_buf *tmp, char **line, int fd)
{
	int				i;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	i = 0;
	while (tmp->s[i] != '\n' && tmp->s[i] != '\r' && tmp->s[i])
		i++;
	if (tmp->s[i] == '\n' || tmp->s[i] == '\r')
		return (ft_line(tmp, line));
	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp->s = ft_realloc(tmp->s, ft_strlen(tmp->s) + ret + 1)))
			return (-1);
		ft_strncat(tmp->s, buf, ret);
		return (ft_getread(tmp, line, fd));
	}
	else if (ret == 0 && ft_strlen(tmp->s) == 0)
		return (0);
	else if (ret == 0)
		return (ft_line(tmp, line));
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static t_buf	file;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	ret = 0;
	if (file.s == NULL)
		if (!(file.s = (char*)malloc(1)))
			return (-1);
	ret = ft_getread(&file, line, fd);
	return (ret);
}
