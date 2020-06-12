/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:04:06 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/20 16:39:34 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			k = i;
			while (needle[j] == haystack[i])
			{
				i++;
				j++;
				if (needle[j] == '\0')
					return ((char*)&haystack[k]);
			}
			i = k;
		}
		i++;
	}
	return (0);
}
