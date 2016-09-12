/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:24:02 by vterzian          #+#    #+#             */
/*   Updated: 2016/09/12 17:57:18 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color1(t_env *e)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		e->f->color[i] = 0x000055 + i;
		e->f->color[i + 256] = 0x000055 - i;
		e->f->color[i + 512] = 0x000055 * i;
		e->f->color[i + 768] = 0x000055 / (i + 1);
		i++;
	}
	return (1);
}

int		ft_color2(t_env *e)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		e->f->color[i] = 0xA0AA00 + i;
		e->f->color[i + 256] = 0xA0AA00 - i;
		e->f->color[i + 512] = 0xA0AA00 * i;
		e->f->color[i + 768] = 0xA0AA00 / (i + 1);
		i++;
	}
	return (1);
}

int		ft_color3(t_env *e)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		e->f->color[i] = 0xAA0000 + i;
		e->f->color[i + 256] = 0xAA0000 - i;
		e->f->color[i + 512] = 0xAA0000 * i;
		e->f->color[i + 768] = 0xAA0000 / (i + 1);
		i++;
	}
	return (1);
}

int		init_palette(t_env *e)
{
	if (e->f->pal == 0)
		ft_color1(e);
	else if (e->f->pal == 1)
		ft_color2(e);
	else if (e->f->pal == 2)
		ft_color3(e);
	return (1);
}
