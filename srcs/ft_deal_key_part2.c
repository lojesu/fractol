/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:07:52 by lojesu            #+#    #+#             */
/*   Updated: 2019/04/15 15:25:35 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_julia_part2(t_win *win)
{
	if (win->val.julia_mod == 3 && win->val.fract == 3)
	{
		win->val.cx = 0.302;
		win->val.cy = 0.012;
	}
	if (win->val.julia_mod == 4 && win->val.fract == 2)
	{
		win->val.cx = -0.4;
		win->val.cy = 0.6;
	}
	if (win->val.julia_mod == 4 && win->val.fract == 3)
	{
		win->val.cx = 0.444;
		win->val.cy = -0.666;
	}
	if (win->val.julia_mod == 5 && win->val.fract == 2)
	{
		win->val.cx = -0.8;
		win->val.cy = 0.156;
	}
	if (win->val.julia_mod == 5 && win->val.fract == 3)
	{
		win->val.cx = -0.348;
		win->val.cy = 0.116;
	}
}

static void	ft_set_julia(t_win *win)
{
	if (win->val.julia_mod == 1 && win->val.fract == 2)
	{
		win->val.cx = 0.3;
		win->val.cy = 0.5;
	}
	if (win->val.julia_mod == 1 && win->val.fract == 3)
	{
		win->val.cx = 0.314;
		win->val.cy = -0.47;
	}
	if (win->val.julia_mod == 2)
	{
		win->val.cx = 0.285;
		win->val.cy = 0.01;
	}
	if (win->val.julia_mod == 3 && win->val.fract == 2)
	{
		win->val.cx = 0.285;
		win->val.cy = 0.013;
	}
	ft_set_julia_part2(win);
}

void		ft_deal_key_part2(int key, t_win *win)
{
	if (key == 43 || key == 47)
	{
		ft_window(win, 0);
		win->val.move = 0;
		if (key == 43 && win->val.fract == 1)
			win->val.mandel_mod -= 1;
		if (key == 47 && win->val.fract == 1)
			win->val.mandel_mod += 1;
		if (key == 43 && (win->val.fract == 2 || win->val.fract == 3))
			win->val.julia_mod -= 1;
		if (key == 47 && (win->val.fract == 2 || win->val.fract == 3))
			win->val.julia_mod += 1;
		if (win->val.julia_mod == 0)
			win->val.julia_mod = 5;
		if (win->val.julia_mod == 6)
			win->val.julia_mod = 1;
		if (win->val.mandel_mod == 0)
			win->val.mandel_mod = 3;
		if (win->val.mandel_mod == 4)
			win->val.mandel_mod = 1;
		ft_set_julia(win);
		ft_window(win, 1);
	}
}
