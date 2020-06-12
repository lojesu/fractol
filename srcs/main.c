/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:08:20 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/15 19:51:13 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"

void		ft_initialize_main(t_zoom *zoom, t_val *val, size_t mod)
{
	zoom->zoom = 1.0;
	zoom->x = 2.0;
	zoom->y = 1.0;
	zoom->julia_x = 1.2;
	zoom->julia_y = 1.2;
	val->ite = 80;
	val->menu = 0;
	if (mod == 1)
	{
		val->mod = 0;
		val->move = 1;
		val->julia_mod = 0;
		val->mandel_mod = 1;
	}
}

static void	ft_usage(size_t mod)
{
	if (mod == 1)
	{
		ft_putendl("usage : fractol [fractals]");
		ft_putendl("--> mandelbrot");
		ft_putendl("--> julia");
		ft_putendl("--> burnjulia");
		ft_putendl("--> tricorn");
		ft_putendl("--> burningship");
	}
	exit(1);
}

static void	ft_parse_part2(t_win *win, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		win->val.fract = 1;
		mandelbrot(win);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		win->val.fract = 2;
		julia(win);
	}
	else if (ft_strcmp(argv[1], "burnjulia") == 0)
	{
		win->val.fract = 3;
		burnjulia(win);
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
	{
		win->val.fract = 4;
		burningship(win);
	}
	else if (ft_strcmp(argv[1], "tricorn") == 0)
	{
		win->val.fract = 5;
		tricorn(win);
	}
}

static void	ft_parse(t_win *win, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0
			|| ft_strcmp(argv[1], "julia") == 0
			|| ft_strcmp(argv[1], "burnjulia") == 0
			|| ft_strcmp(argv[1], "burningship") == 0
			|| ft_strcmp(argv[1], "tricorn") == 0)
	{
		win->mlx_ptr = mlx_init();
		win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, argv[1]);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp), &(win->s_l),
				&(win->endian));
		ft_parse_part2(win, argv);
	}
	else
		ft_usage(1);
}

int			main(int argc, char **argv)
{
	t_win	win;

	pthread_mutex_init(&win.mutex, NULL);
	if (argc >= 2)
	{
		ft_initialize_main(&(win.zoom), &(win.val), 1);
		ft_parse(&win, argv);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img_ptr, 0, 0);
		ft_legends(&win, 0);
		mlx_hook(win.win_ptr, 2, 0, ft_deal_key, &win);
		mlx_hook(win.win_ptr, 6, 0, ft_mouse_move, &win);
		mlx_mouse_hook(win.win_ptr, ft_mouse_hook, &win);
		mlx_loop(win.mlx_ptr);
	}
	else
		ft_usage(1);
	return (0);
}
