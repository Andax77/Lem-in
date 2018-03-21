/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_size_secure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:31:23 by anhuang           #+#    #+#             */
/*   Updated: 2018/02/16 18:31:24 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	min_llu(void)
{
	static unsigned long long a;

	if (!a)
		a = ((unsigned long long)1 << (sizeof(unsigned long long) * 8 - 1));
	return (a);
}

long long			min_ll(void)
{
	static long long a;

	if (!a)
		a = ((long long)1 << (sizeof(long long) * 8 - 1));
	return (a);
}

long				min_l(void)
{
	static long a;

	if (!a)
		a = ((long)1 << (sizeof(long) * 8 - 1));
	return (a);
}

int					min_i(void)
{
	static int a;

	if (!a)
		a = ((int)1 << (sizeof(int) * 8 - 1));
	return (a);
}

char				min_c(void)
{
	static char a;

	if (!a)
		a = ((char)(1 << (sizeof(char) * 8 - 1)));
	return (a);
}
