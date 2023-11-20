/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:32:59 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/17 01:26:28 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	color_atoi(const char *nptr, long int *n)
{
	*n = 0;
	if (!nptr)
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*n = 10 * (*n) + (*nptr - '0');
		if (*n < 0 || *n > 255)
			return (-1);
		nptr++;
	}
	if (*nptr)
		return (-1);
	return (0);
}

float	degree_to_radians(float degree)
{
	return (degree * RAD);
}
