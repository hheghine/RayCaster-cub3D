/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:30:42 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/20 01:59:29 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*get_tex(t_img *img, t_list **anim, int n[0][2])
{
	if (n && anim && *anim && img)
		(*n)[0]--;
	if (!img)
		return (*anim);
	if (!img->img)
	{
		free(img);
		(*n)[1] = 0;
		return (*anim);
	}
	ft_lstadd_back(anim, ft_lstnew(img));
	return (*anim);
}

t_img	*get_texture(t_cub *cub)
{
	t_img	*i;
	float	ray_cos;
	float	ray_sin;

	ray_cos = cub->ray.cos;
	if (ray_cos < 0)
		ray_cos *= -1;
	ray_sin = cub->ray.sin;
	if (ray_sin < 0)
		ray_sin *= -1;
	i = cub->tex.b;
	if (cub->map[(int)(cub->x - ray_sin)][(int)cub->y] != '1')
		i = cub->tex.n->content;
	else if (cub->map[(int)(cub->x + ray_sin)][(int)cub->y] != '1')
		i = cub->tex.s->content;
	else if (cub->map[(int)cub->x][(int)(cub->y + ray_cos)] != '1')
		i = cub->tex.e->content;
	else if (cub->map[(int)cub->x][(int)(cub->y - ray_cos)] != '1')
		i = cub->tex.w->content;
	return (i);
}

int	get_tex_color(t_cub *cub, t_img *img, int z)
{
	int	color;

	color = 0x00000000;
	if (cub->map[(int)cub->x][(int)cub->y] == '1')
		color = my_mlx_pixel_get(img, (int)(img->width * (cub->x + cub->y)) \
			% img->width, z);
	return (color);
}

void	draw_texture(t_cub *cub, t_img *i, int ray_count, int wall_height)
{
	float	dy; // change in height per pixel in the texture
	float	ds; // the starting point for rendering the texture vertically
	float	cy[2];
	int		z;
	int		color;

	dy = ((float)wall_height * 2) / (float)i->height;
	ds = ((float)WIN_H / 2) - (float)wall_height;
	cy[1] = ds; // initial y-coordinate for drawing 
	z = -1;
	while (++z < i->height)
	{
		color = get_tex_color(cub, i, z);
		color = get_shadow_color(color, ds, 0);
		cy[0] = cy[1];
		while (cy[0] < cy[1] + dy)
		{
			if (cy[0] >= 0 && cy[0] < (float)WIN_H)
				my_mlx_pixel_put(&cub->win_img, ray_count, cy[0], color);
			cy[0]++;
		}
		cy[1] += dy;
	}
}