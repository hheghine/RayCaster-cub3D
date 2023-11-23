/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:21:11 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/23 17:43:46 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ceiling_and_floor(t_cub *cub)
{
	unsigned int	*dst;
	unsigned int	i;

	
	dst = (unsigned int *)cub->win_img.addr;
	i = WIN_W * WIN_H / 2 + 1;
	while (--i > 0)
		*dst ++ = cub->tex.ceiling;
		// *dst ++ = 0x0099FFFF;
	i = WIN_W * WIN_H / 2 + 1;
	while (--i > 0)
		*dst ++ = cub->tex.floor;
		// *dst ++ = 0x0099FF00;
}

void	my_mlx_init(t_cub *cub)
{
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIN_W, WIN_H, "Cub3D");
	cub->win_img.img = mlx_new_image(cub->mlx_ptr, WIN_W, WIN_H);
	cub->win_img.addr = mlx_get_data_addr(cub->win_img.img, &cub->win_img.bpp, \
		&cub->win_img.line_len, &cub->win_img.endian);
}

void	full_init(t_cub *cub)
{
	my_mlx_init(cub);
	init_ray(cub);
	// draw_ceiling_and_floor(cub);
	cub_raycast(cub);
	mlx_hook(cub->win_ptr, 02, 1L << 0, cub_keydown, cub);
	mlx_hook(cub->win_ptr, 03, 1L << 1, cub_keyup, cub);
	mlx_hook(cub->win_ptr, 17, 0, cub_exit, cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->win_img.img, 0, 0);
	mlx_loop_hook(cub->mlx_ptr, cub_update, cub);
	mlx_loop(cub->mlx_ptr);
}