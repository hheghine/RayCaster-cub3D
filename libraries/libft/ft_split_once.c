/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_once.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:33:44 by hbalasan          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:00 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_once(char *str, int c)
{
	char	**splitted;
	int		len;
	int		pos;
	int		i[2];

	splitted = (char **)malloc(sizeof(char *) * 3);
	len = ft_strlen(str);
	pos = ft_strchr_idx(str, c);
	splitted[0] = (char *)malloc(sizeof(char) * (pos + 1));
	i[0] = -1;
	while (++i[0] < (pos + 1) && str[i[0]])
		splitted[0][i[0]] = str[i[0]];
	splitted[0][i[0]] = '\0';
	splitted[1] = (char *)malloc(sizeof(char *) * (len - pos + 1));
	i[1] = -1;
	i[0] -= 1;
	while (++i[1] < (len - pos + 1) && str[++i[0]])
		splitted[1][i[1]] = str[i[0]];
	splitted[1][i[1]] = '\0';
	splitted[2] = NULL;
	return (splitted);
}