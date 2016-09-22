/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:21:07 by vterzian          #+#    #+#             */
/*   Updated: 2016/09/22 18:37:30 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_usage(void)
{
	ft_putendl("usage: ./fractol <option>");
	ft_putendl("option 1: Mandelbrot");
	ft_putendl("option 2: Julia");
	ft_putendl("option 3: Burning_ship");
	exit(0);
	return (1);
}

int		ft_key_change(int key, t_env *e)
{
	if (key == K_ONE)
	{
		ft_strdel(&e->type);
		e->type = ft_strdup("Mandelbrot");
		init_fract(e);
	}
	else if (key == K_TWO)
	{
		ft_strdel(&e->type);
		e->type = ft_strdup("Julia");
		init_fract(e);
	}
	else if (key == K_THREE)
	{
		ft_strdel(&e->type);
		e->type = ft_strdup("Burning_ship");
		init_fract(e);
	}
	e->first = 1;
	return (1);
}

int		ft_key_press(int key, t_env *e)
{
	if (key == K_EXIT)
		exit(0);
	else if (key == K_ONE || key == K_TWO || key == K_THREE)
		ft_key_change(key, e);
	else if (key == K_UP)
		e->key &= ~U;
	else if (key == K_DOWN)
		e->key &= ~D;
	else if (key == K_LEFT)
		e->key &= ~L;
	else if (key == K_RIGHT)
		e->key &= ~R;
	else if (key == K_PLUS)
		e->key &= ~P;
	else if (key == K_MINUS)
		e->key &= ~M;
	return (1);
}

int		ft_key_release(int key, t_env *e)
{
	e->first = 1;
	if (key == K_UP)
		e->key |= U;
	else if (key == K_DOWN)
		e->key |= D;
	else if (key == K_LEFT)
		e->key |= L;
	else if (key == K_RIGHT)
		e->key |= R;
	else if (key == K_PONE)
		e->f->pal = 0;
	else if (key == K_PTWO)
		e->f->pal = 1;
	else if (key == K_PTHR)
		e->f->pal = 2;
	else if (key == K_PLUS)
		e->key |= P;
	else if (key == K_MINUS)
		e->key |= M;
	else if (key == K_SPACE)
		e->f->mstp = (e->f->mstp == 0) ? 1 : 0;
	return (1);
}

void	ft_put_pixel_to_img(unsigned long color, t_env *env, int x, int y)
{
	int				i;
	unsigned char	col[(env->img->bpp / 8) - 1];

	i = 0;
	if (x < WIN_W && y < WIN_H && y >= 0 && x >= 0)
	{
		while (i < (env->img->bpp / 8) - 1)
		{
			col[i] = mlx_get_color_value(env->mlx, color) >> (i * 8);
			i++;
		}
		while (i >= 0)
		{
			env->img->data
			[y * env->img->sl + x * env->img->bpp / 8 + i] = col[i];
			i--;
		}
	}
}
