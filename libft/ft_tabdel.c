/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:52:20 by lojesu            #+#    #+#             */
/*   Updated: 2019/02/14 14:45:10 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(void ***tab, size_t i, size_t j)
{
	size_t	x;
	size_t	y;
	void	**tmp;

	if (tab == NULL || *tab == NULL || **tab == NULL)
		return ;
	tmp = *tab;
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			ft_memdel(&tmp[x][y]);
			y++;
		}
		x++;
	}
	free(*tab);
	*tab = NULL;
}
