/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:43:20 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/23 17:46:49 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_keyup(int key, t_cub *cub)
{
	if (key == KEY_R)
		cub->neg *= -1;
	else if (key == KEY_LEFT)
		cub->pl.keys.left_pressed = 0;
	else if (key == KEY_RIGHT)
		cub->pl.keys.right_pressed = 0;
	else if (key == KEY_W)
		cub->pl.keys.w_pressed = 0;
	else if (key == KEY_A)
		cub->pl.keys.a_pressed = 0;
	else if (key == KEY_S)
		cub->pl.keys.s_pressed = 0;
	else if (key == KEY_D)
		cub->pl.keys.d_pressed = 0;
	return (0);
}

int	cub_keydown(int key, t_cub *cub)
{
	if (key == KEY_Q || key == KEY_ESC)
		cub_error(end, 1);
	else if (key == KEY_LEFT)
		cub->pl.keys.left_pressed = 1;
	else if (key == KEY_RIGHT)
		cub->pl.keys.right_pressed = 1;
	else if (key == KEY_W)
		cub->pl.keys.w_pressed = 1;
	else if (key == KEY_A)
		cub->pl.keys.a_pressed = 1;
	else if (key == KEY_S)
		cub->pl.keys.s_pressed = 1;
	else if (key == KEY_D)
		cub->pl.keys.d_pressed = 1;
	return (0);
}
