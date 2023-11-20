/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 02:05:48 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/16 21:38:52 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUBMLX_H__
# define __CUBMLX_H__

typedef struct s_img
{
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* loads XPM image and fills t_img struct for it */
t_img	*mlx_load_img(void *ptr, char *path);

#endif