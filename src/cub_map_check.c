/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:52:16 by hbalasan          #+#    #+#             */
/*   Updated: 2024/02/08 13:22:40 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_walls_2(t_cub *cub, char **map, int i, int j)
{
	printf("i: %d, j: %d '%c'\n", i, j, map[i][j]);
	if (i - 1 >= 0 && i - 1 < cub->height)
	{
		printf("stex\n");
		if (j - 1 >= 0 && j - 1 < (int)ft_strlen(map[i - 1]))
		{
		printf("stex '%c'\n", map[i - 1][j - 1]);
			
			cub_error(inv_wall, ft_strchr_set(&map[i - 1][j - 1], "NSEW") != -1);
		}
		if (j + 1 >= 0 && j + 1 < (int)ft_strlen(map[i - 1]))
		{
		printf("stex1\n");

			cub_error(inv_wall, ft_strchr_set(&map[i - 1][j + 1], "NSEW") != -1);
		}
		if (j >= 0 && j < (int)ft_strlen(map[i - 1]))
			cub_error(inv_wall, ft_strchr_set(&map[i - 1][j], "NSEW") != -1);
	}
	if (j - 1 >= 0 && j - 1 < (int)ft_strlen(map[i]))
		cub_error(inv_wall, ft_strchr_set(&map[i][j - 1], "NSEW") != -1);
	if (j + 1 >= 0 && j + 1 < (int)ft_strlen(map[i]))
		cub_error(inv_wall, ft_strchr_set(&map[i][j + 1], "NSEW") != -1);
	if (i + 1 >= 0 && i + 1 < cub->height)
	{
		if (j - 1 >= 0 && j - 1 < (int)ft_strlen(map[i + 1]))
			cub_error(inv_wall, ft_strchr_set(&map[i + 1][j - 1], "NSEW") != -1);
		if (j + 1 >= 0 && j + 1 < (int)ft_strlen(map[i + 1]))
			cub_error(inv_wall, ft_strchr_set(&map[i + 1][j + 1], "NSEW") != -1);
		if (j >= 0 && j < (int)ft_strlen(map[i + 1]))
			cub_error(inv_wall, map[i + 1][j] == '0');
	}
}

void	check_walls(t_cub *c, char **map, int j, int i)
{
	if (j - 1 >= 0 && j - 1 < c->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			cub_error(inv_wall, map[j - 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			cub_error(inv_wall, map[j - 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			cub_error(inv_wall, map[j - 1][i] == '0');
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		cub_error(inv_wall, map[j][i - 1] == '0');
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		cub_error(inv_wall, map[j][i + 1] == '0');
	if (j + 1 >= 0 && j + 1 < c->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			cub_error(inv_wall, map[j + 1][i - 1] == '0');
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			cub_error(inv_wall, map[j + 1][i + 1] == '0');
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			cub_error(inv_wall, map[j + 1][i] == '0');
	}
	check_walls_2(c, map, j, i);
}

void	check_elements(t_cub *cub, char **map, int i, int j)
{
	if (!cub->pl.dir && ft_strchr("NSEW", map[i][j]))
	{
		cub->pl.dir = map[i][j];
		cub->pl.x = (float)i;
		cub->pl.y = (float)j;
	}
	else if (cub->pl.dir && ft_strchr("NSEW", map[i][j]))
		cub_error(inv_player, 1);
	else if (!ft_strchr("01", map[i][j]))
		cub_error(inv_char, 1);
	if (i == cub->height - 1 && !cub->pl.dir)
		cub_error(inv_player, 1);
}

void	check_elem(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->height)
	{
		j = -1;
		while (++j < cub->width)
		{
			if (cub->map[i][j] == ' ')
				check_walls(cub, cub->map, i, j);
			else
				check_elements(cub, cub->map, i, j);
		}
	}
}

char	**make_map(t_cub *cub)
{
	char	**temp;
	int		i;
	int		j;

	temp = malloc(sizeof(char *) * (cub->height + 1));
	i = -1;
	while (++i < cub->height)
	{
		temp[i] = malloc(sizeof(char) * (cub->width + 1));
		j = -1;
		while (++j < cub->width)
		{
			if (j >= (int)ft_strlen(cub->map[i]))
				temp[i][j] = ' ';
			else
				temp[i][j] = cub->map[i][j];
		}
		temp[i][j] = '\0';
	}
	temp[i] = NULL;
	// for (int i = 0; i < cub->height; i++)
	// {
	// 	for (int j = 0; j < cub->width; j++)
	// 		printf("%c", temp[i][j]);
	// 	printf("\n");
	// }
	return (temp);
}
