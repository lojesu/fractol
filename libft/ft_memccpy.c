/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:59:52 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/21 13:25:31 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		x;
	unsigned char		*ptr1;
	unsigned const char	*ptr2;

	i = 0;
	ptr1 = dst;
	ptr2 = src;
	x = (unsigned char)c;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr2[i] == x)
			return (ptr1 + i + 1);
		if (i == n - 1)
			return (0);
		i++;
	}
	return (0);
}
