/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:06:10 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/20 16:14:46 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	i = 0;
	str = (char*)s;
	x = (char)c;
	while (str[i])
	{
		if (str[i] == x)
		{
			return (&str[i]);
		}
		i++;
	}
	if (x == 0)
		return (&str[i]);
	return (0);
}
