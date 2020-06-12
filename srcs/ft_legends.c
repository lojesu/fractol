/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:24:24 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/15 19:39:57 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <math.h>

static void	ft_menu(t_win *win)
{
	size_t	i;
	size_t	j;

	i = HEIGHT - 400;
	while (i < HEIGHT)
	{
		j = WIDTH - 500;
		while (j < WIDTH)
		{
			mlx_pixel_put(win->win_ptr, win->win_ptr, j, i, 0x666699 +
					pow(j, 17));
			j++;
		}
		i++;
	}
}

static void	ft_legends_part2(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 285,
			0xe9e9e9, "1 to 5: advanced colors");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 250,
			0xe9e9e9, "{ }: change fractal");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 235,
			0xe9e9e9, "< >: change fractal mod");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 470, HEIGHT - 200,
			0xccff66, "JULIA");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 185,
			0xe9e9e9, "right clic: active/desactive parameter changer");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 170,
			0xe9e9e9, "->move the mouse for change the parameter");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 135,
			0xe9e9e9, "TAB: reset");
}

void		ft_legends(t_win *win, size_t mod)
{
	if (mod == 1)
	{
		ft_menu(win);
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 275, HEIGHT - 390,
				0xcc3300, "LEGENDS:");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 350,
				0xe9e9e9, "move: arrow/WASD");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 335,
				0xe9e9e9, "zoom/dezoom: scroll");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 490, HEIGHT - 300,
				0xff0000, "R");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 480, HEIGHT - 300,
				0x00ff00, "G");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 470, HEIGHT - 300,
				0x0000ff, "B");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 460, HEIGHT - 300,
				0xe9e9e9, ": basic colors");
		ft_legends_part2(win);
	}
	else
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH - 90, HEIGHT - 20,
				0xd9d9d9, "(M):Menu");
	}
}
