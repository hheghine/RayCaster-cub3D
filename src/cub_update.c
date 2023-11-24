/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:51:21 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/24 21:02:32 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_anim(t_cub *cub)
{
	cub->tex.n = cub->tex.n->next;
	if (!cub->tex.n)
		cub->tex.n = cub->tex.n_bak;
	cub->tex.s = cub->tex.s->next;
	if (!cub->tex.s)
		cub->tex.s = cub->tex.s_bak;
	cub->tex.e = cub->tex.e->next;
	if (!cub->tex.e)
		cub->tex.e = cub->tex.e_bak;
	cub->tex.w = cub->tex.w->next;
	if (!cub->tex.w)
		cub->tex.w = cub->tex.w_bak;
}

int	cub_update(void *param)
{
	t_cub	*cub;

	cub = param;
	if (!(cub->frames % cub->rate))
	{
		if (!(cub->frames % (2 * cub->rate))) // without this animation was too fast
			update_anim(cub);
		check_move(cub);
		cub_raycast(cub);
		if (cub->neg > 0)
			color_inverter(cub);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->win_img.img, 0, 0);
	}
	cub->frames++;
	return (0);
}