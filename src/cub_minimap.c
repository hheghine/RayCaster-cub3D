/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:57:49 by hbalasan          #+#    #+#             */
/*   Updated: 2024/01/28 01:14:17 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_miniview(t_cub *cub)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x1 = -1;
	x = (cub->pl.y + 0.5) * SIZE - (int)(cub->miniview.height / 2);
	while (++x1 < (cub->miniview.height))
	{
		y1 = -1;
		y = (cub->pl.x + 0.5) * SIZE - (int)(cub->miniview.width / 2);
		while (++y1 < cub->miniview.width)
		{
			if (x >= 0 && x < (cub->height * SIZE) && y >= 0 \
						&& y < (cub->width * SIZE))
				my_mlx_pixel_put(&cub->miniview, y1, x1, \
					my_mlx_pixel_get(&cub->minimap, y, x));
			else
				my_mlx_pixel_put(&cub->miniview, y1, x1, 0xFF000000);
			y++;
		}
		x++;
	}
}

int	get_minimap_color(t_cub *cub, int len, int x, int y)
{
	int	color;

	color = 0xFF000000;
	if (y < len && cub->map[x][y] != '1')
		color = 0x00CC99FF;
	else if (y < len)
		color = 0x009966CC;
	return (color);
}

void	cub_minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	len;

	x = -1;
	while (++x < cub->height)
	{
		y = -1;
		len = ft_strlen(cub->map[x]);
		while (++y < cub->width)
			my_mlx_area_put(&cub->minimap, \
				ft_newvector(y * SIZE, x * SIZE), \
				ft_newvector(SIZE, SIZE), get_minimap_color(cub, len, x, y));
	}
}