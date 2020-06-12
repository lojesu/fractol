/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:12:02 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/02 18:02:26 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	ft_initialize(t_thd *thd, t_zoom *zoom, size_t i, size_t j)
{
	double	crd_x;
	double	crd_y;

	crd_x = j * (2.4 / WIDTH) - zoom->julia_x;
	crd_y = zoom->julia_y - (i * (2.4 / HEIGHT));
	thd->width = crd_x / zoom->zoom + (2.4 - 2 * zoom->julia_x);
	thd->height = crd_y / zoom->zoom + (2.4 - 2 * zoom->julia_y);
	thd->count = 0;
}

static void	ft_calcul(t_win *win, t_val *val, t_zoom *zoom, t_pos *pos)
{
	t_thd	thd;

	ft_initialize(&thd, zoom, pos->i, pos->j);
	while (thd.count < val->ite)
	{
		thd.x_1 = pow(thd.width, 2) - pow(thd.height, 2) + val->cx;
		thd.y_1 = 2 * thd.width * thd.height + val->cy;
		if (pow(thd.x_1, 2) + pow(thd.y_1, 2) > 4)
			break ;
		thd.width = thd.x_1;
		thd.height = thd.y_1;
		thd.count++;
	}
	if (thd.count < val->ite)
		ft_color(win, val, thd.count, pos);
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

void		julia(t_win *win)
{
	pthread_t	thread[HEIGHT];
	size_t		i;

	win->val.i = 0;
	i = 0;
	while (i < HEIGHT)
	{
		pthread_create(&(thread[i]), NULL, ft_thread, win);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
