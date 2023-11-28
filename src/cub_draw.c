/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:35:38 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/27 20:56:15 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_draw(t_cub *cub, int ray_count, float dis)
{
	int		wall_height;
	float	ds; // vertical offset
	int		i;

	wall_height = (int)(WIN_H / (1.5 * dis));
	ds = ((float)WIN_H / 2) - (float)wall_height;
	i = -1;
	while (++i < WIN_H)
	{
		if (i < ds)
			my_mlx_pixel_put(&cub->win_img, ray_count, i, \
				get_shadow_color(cub->tex.ceiling, i, 0));
		else if (i >= (WIN_H / 2) + wall_height)
			my_mlx_pixel_put(&cub->win_img, ray_count, i, \
				get_shadow_color(cub->tex.floor, WIN_H - i, 0));
	}
	draw_texture(cub, get_texture(cub), ray_count, wall_height);
}