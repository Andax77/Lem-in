/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:52:44 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/19 12:28:41 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*widen(char *old, int pos)
{
	char *out;

	if (!(out = (char*)malloc((pos / BS + 1) * BS + 1)))
		return (NULL);
	ft_bzero(out, (pos / BS + 1) * BS + 1);
	if (old)
	{
		ft_memcpy(out, old, (pos / BS) * BS);
		free(old);
	}
	return (out);
}

void				pc_core2(int *tmp, int *pos, int param)
{
	if (param == 4)
		*pos -= *pos - *tmp;
	else
		*tmp = *pos;
}

int					pc_core(char c, int param, int dpos)
{
	static int		pos;
	static char		*buffer;
	int				out;
	static int		tmp;

	if (param == 1)
	{
		if (!(pos % BS) && !(buffer = widen(buffer, pos)))
			return (-1);
		buffer[pos++] = c;
	}
	else if (param == 4 || param == 5)
		pc_core2(&tmp, &pos, param);
	else if (!(param & 1))
	{
		out = buffer ? pos : 0;
		param == 2 ? out = dpos : 1;
		write(1, buffer ? buffer : "", out);
		free(buffer);
		buffer = NULL;
		if (!(pos = 0) && dpos == -1)
			return (-1);
		return (out);
	}
	return (pos);
}

int					pc_print(int pos)
{
	if (pos == -1)
		return (pc_core(0, 0, 0));
	else if (pos == -2)
		return (pc_core(0, 0, -1));
	else
		return (pc_core(0, 2, pos));
}
