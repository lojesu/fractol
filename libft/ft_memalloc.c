/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:37:11 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/20 18:16:09 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*str;
	size_t	i;

	i = 0;
	if (!(mem = (void*)malloc(sizeof(size_t) * size + 1)))
		return (0);
	str = mem;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
