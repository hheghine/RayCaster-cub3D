/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:47:40 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/18 21:17:09 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_cub *cub)
{
	if (cub->pl.dir == 'S')
		cub->ray.angle = 90;
	else if (cub->pl.dir == 'W')
		cub->ray.angle = 180;
	else if (cub->pl.dir == 'N')
		cub->ray.angle = 270;
	cub->ray.angle = 0;
	cub->ray.hfov = 30;
	cub->ray.incr_angle = 2 * cub->ray.hfov / WIN_W;
	cub->ray.precision = 50;
	cub->ray.lim = 11;
}

float	wall_distance(t_cub *cub, float ray_angle)
{
	float	dist;

	cub->ray.sin = sin(degree_to_radians(ray_angle)) / cub->ray.precision;
	cub->ray.cos = cos(degree_to_radians(ray_angle)) / cub->ray.precision;
	cub->x = cub->pl.x + 0.5;
	cub->y = cub->pl.y + 0.5;
	while (!ft_strchr("1", cub->map[(int)cub->x][(int)cub->y]) && \
		sqrt(powf(cub->x - cub->pl.x - 0.5, 2.) + \
		powf(cub->y - cub->pl.y - 0.5, 2.)) < cub->ray.lim)
	{
		cub->x += cub->ray.sin;
		cub->y += cub->ray.cos;
	}
	dist = sqrt(powf(cub->x - cub->pl.x - 0.5, 2.) + powf(cub->y - cub->pl.y - 0.5, 2.)); // Euclidean distance formula
	return (dist * cos(degree_to_radians(ray_angle - cub->ray.angle)));
}

void	cub_raycast(t_cub *cub)
{
	int		ray_count;
	float	ray_angle;
	float	dist;

	ray_count = -1;
	ray_angle = cub->ray.angle - cub->ray.hfov;
	while (++ray_count < WIN_W)
	{
		dist = wall_distance(cub, ray_angle);
		cub_draw(cub, ray_count, dist);
		ray_angle += cub->ray.incr_angle;
	}
}