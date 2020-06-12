/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:16:16 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/21 14:36:13 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t l;

	i = 0;
	j = ft_strlen(dst);
	k = ft_strlen(src);
	l = 0;
	if (size <= j)
		return (k + size);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (src[l] != '\0' && i < (size - 1))
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (j + k);
}
