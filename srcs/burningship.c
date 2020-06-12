/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:32:03 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/06 15:16:41 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "libft.h"

static void	ft_initialize(t_thd *thd, t_zoom *zoom, size_t i, size_t j)
{
	thd->width = ((j * (3.0 / WIDTH)) - zoom->x) / zoom->zoom +
		(3 - 2 * zoom->x) + 1;
	thd->height = (zoom->y - (i * (2.0 / HEIGHT))) / zoom->zoom +
		(2 - 2 * zoom->y);
	thd->p = sqrt(pow(thd->width - 0.25, 2) + pow(thd->height, 2));
	thd->count = 0;
	thd->x = 0;
	thd->y = 0;
}

static void	ft_calcul(t_win *win, t_val *val, t_zoom *zoom, t_pos *pos)
{
	t_thd	thd;

	ft_initialize(&thd, zoom, pos->i, pos->j);
	while (thd.count < val->ite)
	{
		if (thd.count == 0 && (thd.width < thd.p - 2 * pow(thd.p, 2) + 0.25
					|| pow(thd.width + 1, 2) + pow(thd.height, 2) < 0.0625))
		{
			thd.count = val->ite;
			break ;
		}
		thd.x_1 = fabs(pow(thd.x, 2) - pow(thd.y, 2) + thd.width);
		thd.y_1 = fabs(2 * thd.x * thd.y + thd.height);
		if (pow(thd.x_1, 2) + pow(thd.y_1, 2) > 4)
			break ;
		thd.x = thd.x_1;
		thd.y = thd.y_1;
		thd.count++;
	}
	if (thd.count < val->ite)
		ft_color(win, &(win->val), thd.count, pos);
}

static void	*ft_thread(void *arg)
{
	t_win	*win;
	t_pos	pos;

	win = (t_win *)arg;
	pthread_mutex_lock(&win->mutex);
	pos.i = win->val.i++;
	pthread_mutex_unlock(&win->mutex);
	pos.j = 0;
	while (pos.j < WIDTH)
	{
		ft_calcul(win, &(win->val), &(win->zoom), &pos);
		pos.j++;
	}
	pthread_exit(NULL);
}

void		burningship(t_win *win)
{
	pthread_t	thread[HEIGHT];
	size_t		i2;

	win->val.i = 0;
	i2 = 0;
	while (i2 < HEIGHT)
	{
		pthread_create(&(thread[i2]), NULL, ft_thread, win);
		i2++;
	}
	i2 = 0;
	while (i2 < HEIGHT)
	{
		pthread_join(thread[i2], NULL);
		i2++;
	}
}
