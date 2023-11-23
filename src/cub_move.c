/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:35:15 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/23 17:40:56 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(int k, t_cub *cub)
{
	float	angle;
	float	ray_sin;
	float	ray_cos;

	angle = cub->ray.angle;
	if (k == KEY_A)
		angle = cub->ray.angle - 90;
	else if (k == KEY_S)
		angle = cub->ray.angle - 180;
	else if (k == KEY_D)
		angle = cub->ray.angle + 90;
	ray_cos = cos(degree_to_radians(angle)) * cub->pl.speed;
	ray_sin = sin(degree_to_radians(angle)) * cub->pl.speed;
	if (cub->map[(int)(cub->pl.x + 0.5 + \
			(3 * ray_sin))][(int)(cub->pl.y + 0.5)] != '1')
		cub->pl.x += ray_sin;
	if (cub->map[(int)(cub->pl.x + 0.5)][(int)(cub->pl.y + 0.5 + \
		(3 * ray_cos))] != '1')
		cub->pl.y += ray_cos;
}

void	check_move(t_cub *cub)
{
	if (cub->pl.keys.left_pressed)
		cub->ray.angle -= 3;
	if (cub->pl.keys.right_pressed)
		cub->ray.angle += 3;
	if (cub->pl.keys.w_pressed)
		move_player(KEY_W, cub);
	if (cub->pl.keys.a_pressed)
		move_player(KEY_A, cub);
	if (cub->pl.keys.s_pressed)
		move_player(KEY_S, cub);
	if (cub->pl.keys.d_pressed)
		move_player(KEY_D, cub);
}