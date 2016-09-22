/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:21:28 by vterzian          #+#    #+#             */
/*   Updated: 2016/09/22 18:43:15 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				init_thread(t_env *e)
{
	t_thread	th[N_TH];
	pthread_t	pid[N_TH];
	int			i;
	int			j;

	i = -1;
	j = WIN_H / N_TH;
	while (++i < N_TH)
	{
		th[i].start = i * j;
		th[i].end = (i + 1) * j;
		th[i].e = e;
		if (pthread_create(&pid[i], NULL, do_fract, &th[i]))
			exit(0);
	}
	i = -1;
	while (++i < N_TH)
		pthread_join(pid[i], NULL);
	return (1);
}

void			*do_fract(void *t)
{
	int			x;
	int			y;
	t_thread	*th;

	th = t;
	y = th->start;
	while (y < th->end)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (ft_strequ(th->e->type, "Mandelbrot"))
				ft_mandel(th->e, x, y);
			else if (ft_strequ(th->e->type, "Julia"))
				ft_julia(th->e, x, y);
			else if (ft_strequ(th->e->type, "Burning_ship"))
				ft_burning(th->e, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

int				init_fract(t_env *e)
{
	e->f->c_r = (ft_strequ(e->type, "Julia")) ? -0.72691322542185 : 0;
	e->f->c_i = (ft_strequ(e->type, "Julia")) ? 0.124281466072787 : 0;
	e->f->z_r = 0;
	e->f->z_i = 0;
	e->f->tmp = 0;
	e->f->movex = 0;
	e->f->movey = 0;
	e->f->zoom = 1;
	e->f->ite_max = 30;
	e->key = 0;
	e->f->pal = 0;
	return (1);
}

int				ft_move(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	if (e->key & U)
		e->f->movey -= 0.03 / e->f->zoom;
	if (e->key & D)
		e->f->movey += 0.03 / e->f->zoom;
	if (e->key & L)
		e->f->movex -= 0.03 / e->f->zoom;
	if (e->key & R)
		e->f->movex += 0.03 / e->f->zoom;
	if (e->key & P)
		e->f->ite_max += (e->f->ite_max >= 200) ? 0 : 2;
	if (e->key & M && e->f->ite_max > 0)
		e->f->ite_max -= (e->f->ite_max <= 2) ? 0 : 2;
	e->img->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	return (1);
}

int				ft_fond(t_env *e)
{
	int	x;
	int	y;

	y = WIN_H - 30;
	while (y++ < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			ft_put_pixel_to_img(0x000000, e, x, y);
	}
	return (1);
}
