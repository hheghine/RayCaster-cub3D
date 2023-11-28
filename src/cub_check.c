/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:05:02 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/28 19:37:04 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file(int argc, char **argv)
{
	int	fd;

	cub_error(inv_argc, argc != 2);
	if (!ft_strncmp(argv[1], "-h", 3) || \
		!ft_strncmp(argv[1], "--help", 7))
		cub_usage(0);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	cub_error(inv_file,fd < 0);
	if (ft_strrncmp(".cub", argv[1], 4))
		cub_error(inv_format, 1);
}

void	check_map(t_cub *cub)
{
	int	i[2];
	int	w;
	
	i[0] = -1;
	while (++i[0] < cub->height)
	{
		w = ft_strlen(cub->map[i[0]]) - 1;
		i[1] = 0;
		while (cub->map[i[0]][i[1]] == ' ' && i[1] <= w)
			i[1]++;
		while (cub->map[i[0]][w] == ' ' && w > 0)
			w--;
		if (!ft_strncmp(cub->map[i[0]], "", 1))
			cub_error(inv_map, 1);
		if ((i[0] == 0 || i[0] == cub->height - 1) && \
		ft_strlen(cub->map[i[0]]) - ft_charcount(cub->map[i[0]], ' ') - \
		ft_charcount(cub->map[i[0]], '1'))
			cub_error(inv_map, 1);
		else if (w > i[1] && (cub->map[i[0]][i[1]] != '1' || \
		cub->map[i[0]][i[1]] != '1'))
			cub_error(inv_map, 1);
	}
	check_elem(cub);
	cub_error(inv_map, !i[0]);
}

char	**check_map_rgb(t_cub *cub, char **cf, char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			counter++;
	}
	if (counter > 2)
		return (NULL);
	cf = ft_split(str, ',');
	if (!cf || ft_matrixlen(cf) != 3)
	{
		ft_free_matrix(&cf);
		return (NULL);
	}
	for (int i = 0; cf[i]; i++)
	{
		if (!ft_isdigit_str(cf[i]))
		{
			ft_free_matrix(&cf);
			return(NULL);
		}
	}
	return (cf);
}
