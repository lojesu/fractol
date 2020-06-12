/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:59:57 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/15 19:37:37 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom(int x, int y, t_win *win)
{
	ft_window(win, 0);
	win->zoom.zoom *= 1.2;
	win->val.ite += 2;
	if (win->val.fract == 2 || win->val.fract == 3)
	{
		win->zoom.julia_x -= (((double)x - WIDTH / 2) /
				(3 * WIDTH)) / win->zoom.zoom;
		win->zoom.julia_y += (((double)y - HEIGHT / 2) /
				(3 * HEIGHT)) / win->zoom.zoom;
	}
	else
	{
		win->zoom.x -= (((double)x - WIDTH / 2) /
				(3 * WIDTH)) / win->zoom.zoom;
		win->zoom.y += (((double)y - HEIGHT / 2) /
				(3 * HEIGHT)) / win->zoom.zoom;
	}
	ft_window(win, 1);
}

static void	ft_dezoom(int x, int y, t_win *win)
{
	if (win->zoom.zoom > 0.2)
	{
		ft_window(win, 0);
		win->zoom.zoom /= 1.2;
		win->val.ite -= 2;
		if (win->val.fract == 2 || win->val.fract == 3)
		{
			win->zoom.julia_x -= (((double)x - WIDTH / 2) /
					(3 * WIDTH)) / win->zoom.zoom;
			win->zoom.julia_y += (((double)y - HEIGHT / 2) /
					(3 * HEIGHT)) / win->zoom.zoom;
		}
		else
		{
			win->zoom.x -= (((double)x - WIDTH / 2) /
					(3 * WIDTH)) / win->zoom.zoom;
			win->zoom.y += (((double)y - HEIGHT / 2) /
					(3 * HEIGHT)) / win->zoom.zoom;
		}
		ft_window(win, 1);
	}
}

int			ft_mouse_hook(int key, int x, int y, t_win *win)
{
	if (key == 4)
		ft_zoom(x, y, win);
	else if (key == 5)
		ft_dezoom(x, y, win);
	if (key == 2)
	{
		if (win->val.move == 0)
			win->val.move = 1;
		else if (win->val.move == 1)
			win->val.move = 0;
	}
	return (0);
}

int			ft_mouse_move(int x, int y, t_win *win)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && win->val.move != 0
			&& win->val.fract != 3)
	{
		ft_window(win, 0);
		win->val.cx = (double)x / (2 * WIDTH);
		win->val.cy = (double)y / HEIGHT;
		ft_window(win, 1);
	}
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && win->val.move != 0
			&& win->val.fract == 3)
	{
		ft_window(win, 0);
		win->val.cx = ((double)x - (WIDTH / 2)) / (WIDTH / 2);
		win->val.cy = ((double)y - (HEIGHT / 2)) / (HEIGHT / 2);
		ft_window(win, 1);
	}
	return (0);
}
