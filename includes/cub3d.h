/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:53:37 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/28 18:53:43 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H_
# define __CUB3D_H_

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "cuberr.h"
# include "cubmlx.h"
# include "keycodes.h"
# include "get_next_line.h"
# include "../libraries/libft/libft.h"

# ifndef WIN_H
#  define WIN_H 640
# endif

# ifndef WIN_W
#  define WIN_W 820
# endif

# ifndef SIZE
#  define SIZE 7
# endif

# ifndef RAD
#  define RAD 0.01745
# endif

/* rgb colors with transparency */
typedef struct s_color
{
	long	t;
	long	r;
	long	g;
	long	b;
}	t_color;

/* to detect pressed keys */
typedef struct s_key
{
	int	w_pressed;
	int	a_pressed;
	int	s_pressed;
	int	d_pressed;
	int	left_pressed;
	int	right_pressed;
}	t_key;

/* player attributes */
typedef struct s_player
{
	float	x;
	float	y;
	char	dir;
	float	speed;
	t_key	keys;
}	t_player;

/* ray-casting data */
typedef struct s_ray
{
	float	angle;
	float	incr_angle;
	float	sin;
	float	cos;
	float	hfov;
	float	lim;
	int		precision;
}	t_ray;

/* images corresponding to a wall texture */
typedef struct s_tex
{
	t_list	*n;
	t_list	*n_bak;
	t_list	*s;
	t_list	*s_bak;
	t_list	*w;
	t_list	*w_bak;
	t_list	*e;
	t_list	*e_bak;
	t_img	*b;
	int		floor;
	int		ceiling;
}	t_tex;

/* the main structure */
typedef struct s_cub
{
	int			fd;
	char		**map;
	int			height;
	int			width;
	int			rate;
	int			neg;
	long		frames;
	t_tex		tex;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_player	pl;
	t_ray		ray;
	float		x;
	float		y;
}	t_cub;


/* checks the input file */
void			check_file(int argc, char **argv);

/* adds spaces to end of all lines to make a square map */
char			**make_map(t_cub *cub);

/* checks the map */
void			check_map(t_cub *cub);

/* checks the map characters */
void			check_elem(t_cub *cub);

/* checks and retrieves floor and ceiling colors from map */
char	**check_map_rgb(t_cub *cub, char **cf, char *str);

/* reads file with gnl */
void			read_map(char *file, t_cub *cub);

/* cub3d init */
void			full_init(t_cub *cub);

/* free, destroy */
void			cub_end(t_cub *g);

/* atoi for RGB colors */
int				color_atoi(const char *nptr, long int *n);

/* 1° × π/180 = 0.01745rad */
float			degree_to_radians(float degree);

/* gets the ceiling and floor colors */
void			get_cf_colors(t_cub *cub, char **str);

/* initializes raycast data */
void			init_ray(t_cub *cub);

/* shoot rays in a given direction to find walls */
void			cub_raycast(t_cub *cub);

/* retrieves RGB from int */
t_color			create_trgb(int color);

/* makes int out of RGB */
int				color_trgb(t_color c);

/* draws 3D view on window-sized image */
void			cub_draw(t_cub *g, int ray_count, float dis);

/* sets color for a pixel at a position on an image */
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* makes the color darker as the object gets further by decreasing RGB */
int				get_shadow_color(int color, float ds, int tr);

/* retrieves int color at given position from an image */
unsigned int	my_mlx_pixel_get(t_img *data, int x, int y);

/* retrieves the color of a specific pixel from a texture image */
int				get_tex_color(t_cub *cub, t_img *img, int z);

/* takes a texture image, loops through its height, retrieves colors, and render it vertically on the screen */
void			draw_texture(t_cub *cub, t_img *i, int ray_count, int wall_height);

/* checks which wall has been hit to choose proper texture */
t_img			*get_texture(t_cub *cub);

/* makes a list of textures to make a wall animation */
t_list			*get_tex(t_img *img, t_list **anim, int n[0][2]);

/* redraws the cub3d image */
int				cub_update(void *param);

/* checks keys pressed and changes the image as it should */
void			check_move(t_cub *cub);

/* checks the keyup events */
int	cub_keyup(int key, t_cub *cub);

/* checks the keydown events */
int	cub_keydown(int key, t_cub *cub);

/* ends the game */
int				cub_exit(void *param);

/* inverts map colors */
void			color_inverter(t_cub *cub);

#endif