#include "fractol.h"

int				do_fract(t_env *e, int (*f)(t_env *e, int x, int y))
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			f(e, x, y);
			y++;
		}
		x++;
	}
	return (1);
}
