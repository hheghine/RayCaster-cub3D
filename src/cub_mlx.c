/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:59:37 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/18 15:31:07 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*mlx_load_img(void *ptr, char *path)
{
	int		fd;
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->img = NULL;
	if (!path || ft_strrncmp(path, ".xpm", 4))
		return (i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (i);
	close(fd);
	i->img = mlx_xpm_file_to_image(ptr, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_len, &i->endian);
	return (i);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}
