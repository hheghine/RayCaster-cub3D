/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:37:42 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/20 01:59:04 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_images(t_cub *cub)
{
	if (cub->tex.b && cub->tex.b->img)
		mlx_destroy_image(cub->mlx_ptr, cub->tex.b->img);
	if (cub->win_img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->win_img.img);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	free(cub->tex.b);
}

void	cub_end(t_cub *cub)
{
	if (!cub)
		return ;
	ft_free_matrix(&cub->map);
	if (cub->fd > 0)
		close(cub->fd);
	destroy_images(cub);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
}