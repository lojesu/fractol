/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:06:09 by lojesu            #+#    #+#             */
/*   Updated: 2019/05/02 18:56:07 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000
# define HEIGHT 900

# include <string.h>
# include <pthread.h>

typedef	struct	s_zoom
{
	double		zoom;
	double		x;
	double		y;
	double		julia_x;
	double		julia_y;
}				t_zoom;

typedef	struct	s_val
{
	size_t		ite;
	size_t		mod;
	size_t		fract;
	size_t		move;
	size_t		julia_mod;
	size_t		mandel_mod;
	size_t		menu;
	int			i;
	double		cx;
	double		cy;
}				t_val;

typedef	struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef	struct	s_thd
{
	size_t		count;
	double		x;
	double		y;
	double		x_1;
	double		y_1;
	double		width;
	double		height;
	double		p;
}				t_thd;

typedef	struct	s_pos
{
	size_t		i;
	size_t		j;
}				t_pos;

typedef	struct	s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				s_l;
	int				endian;
	t_rgb			rgb;
	t_zoom			zoom;
	t_val			val;
	pthread_mutex_t	mutex;
}				t_win;

int				ft_deal_key(int key, t_win *win);
void			ft_deal_key_part2(int key, t_win *win);
int				ft_mouse_hook(int key, int x, int y, t_win *win);
int				ft_mouse_move(int x, int y, t_win *win);
void			ft_fill_pixel(t_win *win, int x, int y, t_rgb rgb);
void			ft_color(t_win *win, t_val *val, size_t count, t_pos *pos);
void			mandelbrot(t_win *win);
void			mandelbrot2(t_win *win);
void			mandelbrot3(t_win *win);
void			julia(t_win *win);
void			burnjulia(t_win *win);
void			tricorn(t_win *win);
void			burningship(t_win *win);
void			ft_legends(t_win *win, size_t mod);
void			ft_window(t_win *win, size_t mod);
void			ft_initialize_main(t_zoom *zoom, t_val *val, size_t mod);

#endif
