/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:38:08 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/02 13:23:12 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdlib.h>

static void	ft_colors(int key, t_win *win)
{
	ft_window(win, 0);
	if (key == 18)
		win->val.mod = 0;
	if (key == 19)
		win->val.mod = 1;
	if (key == 20)
		win->val.mod = 2;
	if (key == 21)
		win->val.mod = 3;
	if (key == 23)
		win->val.mod = 4;
	if (key == 15)
		win->val.mod = 10;
	if (key == 5)
		win->val.mod = 11;
	if (key == 11)
		win->val.mod = 12;
	ft_window(win, 1);
}

static void	ft_arrow(int key, t_win *win)
{
	ft_window(win, 0);
	if (key == 126 || key == 13)
	{
		win->zoom.y -= 0.01 / win->zoom.zoom;
		win->zoom.julia_y -= 0.01 / win->zoom.zoom;
	}
	else if (key == 125 || key == 1)
	{
		win->zoom.y += 0.01 / win->zoom.zoom;
		win->zoom.julia_y += 0.01 / win->zoom.zoom;
	}
	else if (key == 124 || key == 2)
	{
		win->zoom.x -= 0.01 / win->zoom.zoom;
		win->zoom.julia_x -= 0.01 / win->zoom.zoom;
	}
	else if (key == 123 || key == 0)
	{
		win->zoom.x += 0.01 / win->zoom.zoom;
		win->zoom.julia_x += 0.01 / win->zoom.zoom;
	}
	ft_window(win, 1);
}

static void	ft_menu(int key, t_win *win)
{
	if (key == 30 || key == 33)
	{
		ft_window(win, 0);
		if (key == 30)
			win->val.fract += 1;
		if (key == 33)
			win->val.fract -= 1;
		if (win->val.fract == 0)
			win->val.fract = 5;
		if (win->val.fract == 6)
			win->val.fract = 1;
		ft_window(win, 1);
	}
	if (key == 46)
	{
		ft_window(win, 0);
		win->val.move = 0;
		if (win->val.menu == 0)
			win->val.menu = 1;
		else
			win->val.menu = 0;
		ft_window(win, 1);
		ft_legends(win, win->val.menu);
	}
}

static void	ft_ite_and_tab(int key, t_win *win)
{
	if (key == 24 || key == 27)
	{
		ft_window(win, 0);
		if (key == 24 && win->val.ite < pow(2, 63))
			win->val.ite += 2;
		else if (key == 27 && win->val.ite > 15)
			win->val.ite -= 2;
		ft_window(win, 1);
	}
	else if (key == 48)
	{
		ft_window(win, 0);
		ft_initialize_main(&(win->zoom), &(win->val), 0);
		ft_window(win, 1);
	}
}

int			ft_deal_key(int key, t_win *win)
{
	ft_colors(key, win);
	ft_arrow(key, win);
	ft_menu(key, win);
	ft_ite_and_tab(key, win);
	ft_deal_key_part2(key, win);
	if (key == 53)
		exit(1);
	return (0);
}
