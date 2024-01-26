/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:10:02 by hbalasan          #+#    #+#             */
/*   Updated: 2024/01/26 17:24:51 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_err(void)
{
	ft_putstr_fd("\033[1;33m⚠ cub3D: error: \033[0;33m", 2);
}

int	cub_error(t_cub_err err, int flag)
{
	if (!flag)
		return (0);
	if (err != end)
		print_err();
	write(2, "invalid number of arguments\n", 28 * (err == inv_argc));
	write(2, "wrong file format\n", 18 * (err == inv_format));
	write(2, "file is empty\n", 14 *(err == empty_file));
	write(2, "file is invalid\n", 16 * (err == inv_file));
	write(2, "device out of memory\n", 21 * (err == no_mem));
	write(2, "invalid texture file\n", 21 * (err == inv_tex));
	write(2, "invalid map\n", 12 * (err == inv_map));
	write(2, "map not surrounded by walls\n", 28 * (err == inv_wall));
	write(2, "only single player is allowed\n", 30 * (err == inv_player));
	write(2, "invalid map character is detected\n", 34 * (err == inv_char));
	if (err == inv_argc && ft_putchar_fd('\n', 2))
		cub_usage(1);
	// system("leaks cub3d");
	if (err == end)
		exit(0);
	exit(1);
	return (1);
}

void	cub_usage(int err)
{
	ft_putstr_fd("\033[0;35mCub3D\nA simple raycaster with MinilibX\n\n", 2);
	ft_putstr_fd("usage: cub3d <map_file.cub>\n", 2);
	exit(err);
}
