/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:44:13 by lojesu            #+#    #+#             */
/*   Updated: 2019/02/14 14:47:46 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel_char(char ***tab)
{
	size_t	i;
	char	**tmp;

	if (tab == NULL || *tab == NULL)
		return ;
	i = 0;
	tmp = *tab;
	while (tmp[i] != 0)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
