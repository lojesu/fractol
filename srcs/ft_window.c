/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:18:03 by lojesu            #+#    #+#             */
/*   Updated: 2019/04/15 15:28:51 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	ft_put_image(t_win *win)
{
	if (win->val.fract == 1)
	{
		if (win->val.mandel_mod == 1)
			mandelbrot(win);
		else if (win->val.mandel_mod == 2)
			mandelbrot2(win);
		else if (win->val.mandel_mod == 3)
			mandelbrot3(win);
	}
	else if (win->val.fract == 2)
		julia(win);
	else if (win->val.fract == 3)
		burnjulia(win);
	else if (win->val.fract == 4)
		burningship(win);
	else if (win->val.fract == 5)
		tricorn(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			0, 0);
	ft_legends(win, 0);
}

void		ft_window(t_win *win, size_t mod)
{
	if (mod == 0)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
	}
	else
		ft_put_image(win);
}
