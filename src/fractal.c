/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:24:10 by vterzian          #+#    #+#             */
/*   Updated: 2016/09/22 17:20:27 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_burning(t_env *e, int x, int y)
{
	int		i;

	e->f->c_r = 1.5 * (x - WIN_W / 2) / (0.5 * e->f->zoom * WIN_W)
				+ e->f->movex;
	e->f->c_i = (y - WIN_H / 2) / (0.5 * e->f->zoom * WIN_H) + e->f->movey;
	e->f->z_r = 0;
	e->f->z_i = 0;
	i = 0;
	while (e->f->z_r * e->f->z_r + e->f->z_i * e->f->z_i <= 4
			&& i < e->f->ite_max)
	{
		e->f->tmp = e->f->z_r;
		e->f->z_r = (e->f->tmp * e->f->tmp > 0) ? (e->f->tmp * e->f->tmp) :
					-(e->f->tmp * e->f->tmp);
		e->f->z_r -= e->f->z_i * e->f->z_i + e->f->c_r;
		e->f->z_i = (e->f->tmp * e->f->z_i > 0) ? 2 * (e->f->tmp * e->f->z_i) :
					2 * -(e->f->tmp * e->f->z_i);
		e->f->z_i += e->f->c_i;
		i++;
	}
	ft_put_pixel_to_img(e->f->color[i * (N_COLOR - 1) / e->f->ite_max],
						e, x, y);
	return (1);
}

int		ft_julia(t_env *e, int x, int y)
{
	int		i;

	e->f->z_r = 2 * (x - WIN_W / 2) / (0.5 * e->f->zoom * WIN_W) + e->f->movex;
	e->f->z_i = 1.1 * (y - WIN_H / 2) / (0.5 * e->f->zoom * WIN_H)
				+ e->f->movey;
	i = 0;
	while (i < e->f->ite_max && ((e->f->z_r * e->f->z_r)
			+ (e->f->z_i * e->f->z_i)) < 4)
	{
		e->f->tmp = e->f->z_r;
		e->f->z_r = (e->f->z_r * e->f->z_r) - (e->f->z_i * e->f->z_i)
					+ e->f->c_r;
		e->f->z_i = (2 * e->f->z_i * e->f->tmp) + e->f->c_i;
		i++;
	}
	if (i == e->f->ite_max)
		ft_put_pixel_to_img(0x000000, e, x, y);
	else
	{
		i -= log(log((e->f->z_r * e->f->z_r) + (e->f->z_i * e->f->z_i)))
			/ log(2);
		ft_put_pixel_to_img(e->f->color[i * (N_COLOR - 1) / e->f->ite_max],
							e, x, y);
	}
	return (1);
}

int		ft_mandel(t_env *e, int x, int y)
{
	int		i;

	e->f->c_r = 2 * (x - WIN_W / 2) / (0.5 * e->f->zoom * WIN_W) + e->f->movex;
	e->f->c_i = 1.1 * (y - WIN_H / 2) / (0.5 * e->f->zoom * WIN_H)
				+ e->f->movey;
	e->f->z_r = 0;
	e->f->z_i = 0;
	i = 0;
	while (i < e->f->ite_max && ((e->f->z_r * e->f->z_r)
			+ (e->f->z_i * e->f->z_i)) < 4)
	{
		e->f->tmp = e->f->z_r;
		e->f->z_r = (e->f->z_r * e->f->z_r) - (e->f->z_i * e->f->z_i)
					+ e->f->c_r;
		e->f->z_i = (2 * e->f->z_i * e->f->tmp) + e->f->c_i;
		i++;
	}
	if (i == e->f->ite_max)
		ft_put_pixel_to_img(0x000000, e, x, y);
	else
		ft_put_pixel_to_img(e->f->color[i * ((3 * 256) - 1) / e->f->ite_max],
							e, x, y);
	return (1);
}
