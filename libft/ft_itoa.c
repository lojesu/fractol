/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:53:35 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/21 13:40:11 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_itoa_neg(int n)
{
	int		i;
	long	nb;
	char	*str;

	i = 1;
	nb = n;
	while (n <= -1)
	{
		n = n / 10;
		i++;
	}
	if (!((str = (char*)malloc(sizeof(char) * i + 1))))
		return (0);
	str[i] = '\0';
	while (i >= 1)
	{
		i--;
		str[i] = -nb % 10 + 48;
		nb = nb / 10;
	}
	str[i] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	if (n < 0)
		return (ft_itoa_neg(n));
	if (n == 0)
		i = 1;
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	if (!((str = (char*)malloc(sizeof(char) * i + 1))))
		return (0);
	str[i] = '\0';
	while (i >= 0)
	{
		i--;
		str[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}
