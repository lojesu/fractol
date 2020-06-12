/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:45:37 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/20 16:14:59 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	i = 0;
	x = (char)c;
	str = (char*)s;
	while (str[i])
		i++;
	while (i > -1)
	{
		if (str[i] == x)
		{
			return (&str[i]);
		}
		i--;
	}
	if (x == 0)
		return (&str[i]);
	return (0);
}
