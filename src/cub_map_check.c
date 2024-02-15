/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:52:16 by hbalasan          #+#    #+#             */
/*   Updated: 2024/02/15 15:05:33 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_walls(t_cub* c, char** map, int j, int i) {
    if (j - 1 >= 0 && j - 1 < c->height) {
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
    if (j + 1 >= 0 && j + 1 < c->height) {
        if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
            cub_error(inv_wall, map[j + 1][i - 1] == '0');
        if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
            cub_error(inv_wall, map[j + 1][i + 1] == '0');
        if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
            cub_error(inv_wall, map[j + 1][i] == '0');
    }
}

void check_elements(t_cub* cub, char** map, int i, int j) {
    if (!cub->pl.dir && ft_strchr("NSEW", map[i][j])) {
        cub->pl.dir = map[i][j];
        cub->pl.x = (float)i;
        cub->pl.y = (float)j;
        if (i == cub->height - 1 || j == cub->width - 1 || i == 0 || j == 0)
            cub_error(inv_map, 1);
        if (!ft_strchr("01", map[i + 1][j]) || !ft_strchr("01", map[i - 1][j]) ||
            !ft_strchr("01", map[i + 1][j - 1]) || !ft_strchr("01", map[i + 1][j + 1]) ||
            !ft_strchr("01", map[i - 1][j - 1]) || !ft_strchr("01", map[i - 1][j + 1]) ||
            !ft_strchr("01", map[i][j - 1]) || !ft_strchr("01", map[i][j + 1]))
            cub_error(inv_player, 1);

    } else if (cub->pl.dir && ft_strchr("NSEW", map[i][j]))
        cub_error(inv_player, 1);
    else if (!ft_strchr("01", map[i][j]))
        cub_error(inv_char, 1);
    if (i == cub->height - 1 && !cub->pl.dir)
        cub_error(inv_player, 1);
}

void check_elem(t_cub* cub) {
    int i;
    int j;

    i = -1;
    while (++i < cub->height) {
        j = -1;
        while (++j < cub->width) {
            if (cub->map[i][j] == ' ')
                check_walls(cub, cub->map, i, j);
            else
                check_elements(cub, cub->map, i, j);
        }
    }
}

char** make_map(t_cub* cub) {
    char** temp;
    int i;
    int j;

    temp = malloc(sizeof(char*) * (cub->height + 1));
    i = -1;
    while (++i < cub->height) {
        temp[i] = malloc(sizeof(char) * (cub->width + 1));
        j = -1;
        while (++j < cub->width) {
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
