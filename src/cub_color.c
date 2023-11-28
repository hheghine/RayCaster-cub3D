/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:16:28 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/28 19:35:28 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color	create_trgb(int color)
{
	t_color	c;

	c.t = (color >> 24) & 0xFF;
	c.r = (color >> 16) & 0xFF;
	c.g = (color >> 8) & 0xFF;
	c.b = color & 0xFF;
	return (c);
}

int	color_trgb(t_color c)
{
	return (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
}

void	get_cf_colors(t_cub *cub, char **str)
{
	t_color	c;
	char	**cf;
	int		tex[2];
	int		color[3];
	
	c.t = 0;
	tex[0] = !ft_strncmp(str[0], "F", 2);
	tex[1] = !ft_strncmp(str[0], "C", 2);
	cf = check_map_rgb(cub, cf, str[1]);
	// cf = ft_split(str[1], ',');
	if (!cf || ft_matrixlen(cf) != 3)
	{
		ft_free_matrix(&cf);
		cub_error(inv_map, 1);
	}
	// for (int j = 0; j < 3; j++)
	// 	printf("color: %s\n", cf[j]);
	color[0] = color_atoi(cf[0], &c.r);
	color[1] = color_atoi(cf[1], &c.g);
	color[2] = color_atoi(cf[2], &c.b);
	ft_free_matrix(&cf);
	if (color[0] || color[1] || color[2])
		return ;
	if (tex[0])
		cub->tex.floor = color_trgb(c);
	else if (tex[1])
		cub->tex.ceiling = color_trgb(c);
}

int	get_shadow_color(int color, float ds, int tr)
{
	t_color	c;
	float	dif;

	if (ds < 0)
		ds = 0;
	dif = powf(1.14, ds / 7.5);
	c = create_trgb(color);
	if (tr)
		c.t -= dif;
	else
		c.t = 256;
	c.r -= dif;
	c.g -= dif;
	c.b -= dif;
	if (c. t < 0)
		c.t = 0;
	if (c.r < 0)
		c.r = 0;
	if (c.g < 0)
		c.g = 0;
	if (c.b < 0)
		c.b = 0;
	return (color_trgb(c));
}

void	color_inverter(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_H)
	{
		y = -1;
		while (++y < WIN_W)
		{
			my_mlx_pixel_put(&cub->win_img, y, x, 0xFFFFFF - \
				my_mlx_pixel_get(&cub->win_img, y, x));
		}
	}
}