/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:48:37 by hbalasan          #+#    #+#             */
/*   Updated: 2023/01/26 16:47:38 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			*(unsigned char *)(dst + (len)) = *(unsigned char *)(src + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
