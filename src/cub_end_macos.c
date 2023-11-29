/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_end_macos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:54:46 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/29 20:56:18 by hbalasan         ###   ########.fr       */
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
}

int	cub_exit(void *param)
{
	cub_error(end, 1);
	return (0);
}