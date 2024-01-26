/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:40:35 by hbalasan          #+#    #+#             */
/*   Updated: 2024/01/26 17:53:50 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_sprites(t_cub *cub)
{
	cub->win_img.img = NULL;
	cub->tex.n = NULL;
	cub->tex.n_bak = NULL;
	cub->tex.s = NULL;
	cub->tex.s_bak = NULL;
	cub->tex.e = NULL;
	cub->tex.e_bak = NULL;
	cub->tex.w = NULL;
	cub->tex.w_bak = NULL;
	cub->tex.b = mlx_load_img(cub->mlx_ptr, "textures/torch/black.xpm");
}


static t_cub	cub_init(void)
{
	t_cub	cub;

	cub.fd = -1;
	cub.height = 0;
	cub.width = 0;
	cub.frames = 0;
	cub.map = NULL;
	cub.pl.dir = 0;
	cub.mlx_ptr = NULL;
	cub.mlx_ptr = mlx_init();
	cub.win_ptr = NULL;
	init_sprites(&cub);
	cub.tex.floor = -1;
	cub.tex.ceiling = -1;
	cub.pl.x = -1;
	cub.pl.y = -1;
	cub.pl.speed = 0.12;
	ft_bzero(&cub.pl.keys, sizeof(t_key));
	cub.neg = -1;
	cub.rate = 30;
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	char	**map;
	
	check_file(argc, argv);
	cub = cub_init();
	read_map(argv[1], &cub);
	map = make_map(&cub);
	ft_free_matrix(&cub.map);
	cub.map = map;
	check_map(&cub);
	full_init(&cub);
	cub_end(&cub);
}