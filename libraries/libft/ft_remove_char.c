/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:32:00 by hbalasan          #+#    #+#             */
/*   Updated: 2024/01/28 23:43:51 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_count(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}

char	*ft_remove_char(char *str, char c)
{
	char	*aux;
	int		count;
	int		i;
	int		j;

	count = ft_char_count(str, c);
	aux = (char *)malloc(ft_strlen(str) - count + 1);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != c)
		{
			aux[j] = str[i];
			j++;
		}
	}
	aux[j] = 0;
	return (aux);
}