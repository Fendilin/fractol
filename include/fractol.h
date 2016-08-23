#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

# define WIN_W		1900
# define WIN_H		1000
# define N_COLOR 	4 * 256

# define K_EXIT		53
# define K_ONE		18
# define K_TWO		19
# define K_THREE	20
# define K_UP		13
# define K_DOWN		1
# define K_LEFT		0
# define K_RIGHT	2
# define K_PONE		83
# define K_PTWO		84
# define K_PTHR		85
# define K_PLUS		69
# define K_MINUS	78
# define K_SPACE	49

# define PMM		(1L << 6)
# define MN			6

enum	e_keys
{
	U = 0x1,
	D = 0x2,
	R = 0x4,
	L = 0x8,
	P = 0x10,
	M = 0x20,
};

typedef struct s_fract	t_fract;
struct					s_fract
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	movex;
	float	movey;
	float	tmp;
	float	zoom;
	int		ite_max;
	int		pal;
	float	color[N_COLOR];
	float	newton;
	int		mstp;
};

typedef struct s_img	t_img;
struct					s_img
{
	void	*img;
	int		bpp;
	int		sl;
	int		ed;
	char	*data;
};

typedef struct s_env	t_env;
struct					s_env
{
	void	*mlx;
	void	*win;
	t_fract	*f;
	t_img	*img;
	char	*type;
	int		key;
};

void		ft_put_pixel_to_img(unsigned long color, t_env *e, int x, int y);
int			init_fract(t_env *e);
int			ft_move(t_env *e);
int			ft_key_press(int key, t_env *e);
int			ft_key_release(int key, t_env *e);
int			ft_motion(int x, int y, t_env *e);
int			do_fract(t_env *e, int (*f)(t_env *e, int x, int y));
int			ft_mandel(t_env *e, int x, int y);
int			ft_julia(t_env *e, int x, int y);
int			ft_burning(t_env *e, int x, int y);
int			ft_usage(void);
#endif
