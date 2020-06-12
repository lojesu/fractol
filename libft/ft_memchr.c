/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:29:01 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/20 19:00:15 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	x;

	i = 0;
	str = (char*)s;
	x = (char)c;
	while (i < n)
	{
		if (str[i] == x)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
