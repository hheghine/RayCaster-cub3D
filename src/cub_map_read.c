/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:05:59 by hbalasan          #+#    #+#             */
/*   Updated: 2024/01/26 17:50:21 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_textures(char	*line, t_cub *c, int n[0][2])
{
	char	**dir;

	dir = ft_split(line, ' ');
	if (!dir)
	{
		free(line);
		cub_error(no_mem, 1);
	}
	if (!*dir ||!*(dir + 1))
	{
		free(line);
		cub_error(inv_tex, 1);
	}
	if (!ft_strncmp(dir[0], "NO", 3))
		c->tex.n_bak = get_tex(mlx_load_img(c->mlx_ptr, dir[1]), &c->tex.n, n);
	else if (!ft_strncmp(dir[0], "SO", 3))
		c->tex.s_bak = get_tex(mlx_load_img(c->mlx_ptr, dir[1]), &c->tex.s, n);
	else if (!ft_strncmp(dir[0], "EA", 3))
		c->tex.e_bak = get_tex(mlx_load_img(c->mlx_ptr, dir[1]), &c->tex.e, n);
	else if (!ft_strncmp(dir[0], "WE", 3))
		c->tex.w_bak = get_tex(mlx_load_img(c->mlx_ptr, dir[1]), &c->tex.w, n);
	if (((!ft_strncmp(dir[0], "F", 2) && c->tex.floor == -1) || \
		(!ft_strncmp(dir[0], "C", 2) && c->tex.ceiling == -1)))
			get_cf_colors(c, dir);
	if (ft_strncmp(dir[0], "NO", 3) && ft_strncmp(dir[0], "SO", 3) && ft_strncmp(dir[0], "EA", 3) \
	&& ft_strncmp(dir[0], "WE", 3) && ft_strncmp(dir[0], "C", 2) && ft_strncmp(dir[0], "F", 2))
	{
		free(line);
		ft_free_matrix(&dir);
		cub_error(inv_tex, 1);
	}
	ft_free_matrix(&dir);
}

void	check_cf(char *line, int n[0][2])
{
	char	**aux;

	aux = ft_split(line, ' ');
	if (!aux)
		cub_error(no_mem, 1);
	if (!ft_strncmp(aux[0], "C", 2))
		(*n)[0] ++;
	else if (!ft_strncmp(aux[0], "F", 2))
		(*n)[1] ++;
	if ((*n)[0] > 1 || (*n)[1] > 1)
		cub_error(inv_tex, 1);
	ft_free_matrix(&aux);
}

void	read_map(char *file, t_cub *cub)
{
	char	*line[2];
	int		i[2];
	int		n[2];

	i[0] = -1;
	i[1] = -1;
	n[0] = 0;
	n[1] = 0;
	cub->fd = open(file, O_RDONLY);
	cub_error(inv_file, cub->fd < 0);
	while (1)
	{
		line[0] = get_next_line(cub->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n");
		free(line[0]);
		if (line[1] && line[1][0] && ++i[0] < 6)
		{
			check_cf(line[1], &n);
			check_textures(line[1], cub, &i);
		}
		else if ((line[1] && line[1][0]) || i[0] >= 6)
			cub->map = ft_extend_matrix(cub->map, line[1]);
		if ((int)ft_strlen(line[1]) > cub->width)
			cub->width = ft_strlen(line[1]);
		free(line[1]);
	}
	cub_error(empty_file, !i[0]);
	cub_error(inv_tex, !i[1]);
	cub->height = ft_matrixlen(cub->map);
}