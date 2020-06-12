/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:35:30 by lojesu            #+#    #+#             */
/*   Updated: 2019/01/14 16:51:32 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, size_t c, char *mod)
{
	char	*tmp;

	if (!str)
		return (0);
	if (c >= ft_strlen(str))
		return (0);
	tmp = "";
	tmp = ft_strdup(str);
	if (ft_strcmp(mod, "avant") == 0)
	{
		ft_strclr(&tmp[c]);
		c = 0;
	}
	else if (strcmp(mod, "apres") == 0)
	{
	}
	else
		return (0);
	return (&tmp[c]);
}
