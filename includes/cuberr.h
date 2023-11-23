/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuberr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:13:57 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/23 14:47:02 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUBERR_H__
# define __CUBERR_H__

typedef enum e_cub_err
{
	inv_argc,
	inv_file,
	inv_format,
	empty_file,
	inv_map,
	inv_tex,
	no_mem,
	inv_wall,
	inv_player,
	inv_char,
	end
}	t_cub_err;

/* generates error messages */
int		cub_error(t_cub_err err, int flag);

/* prints cub3d usage */
void	cub_usage(int err);

#endif