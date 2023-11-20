/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:48:30 by hbalasan          #+#    #+#             */
/*   Updated: 2023/02/01 18:19:57 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_cntr(int c)
{
	int	i;

	i = 0;
	if (c > -1 && i < 10)
		i++;
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int	check_num(int c)
{
	int	i;

	i = 0;
	if (c < 0)
	{
		i++;
		i += digit_cntr(-c);
	}
	else
		i = digit_cntr(c);
	return (i);
}

char	*ft_itoa(int c)
{
	char	*str;
	int		i;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	i = check_num(c);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	*(str + i) = '\0';
	i--;
	if (c == 0)
		*str = '0';
	if (c < 0)
	{
		*str = '-';
		c *= -1;
	}
	while (c > 0)
	{
		*(str + i--) = (c % 10) + '0';
		c = c / 10;
	}
	return (str);
}
