/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:17:17 by hbalasan          #+#    #+#             */
/*   Updated: 2023/01/27 15:06:52 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	while (*(src + j) && (i + j + 1) < dstsize)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i < dstsize)
		*(dst + i + j) = '\0';
	return (i + ft_strlen(src));
}
