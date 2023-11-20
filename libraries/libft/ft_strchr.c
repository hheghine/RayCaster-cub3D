/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:06:09 by hbalasan          #+#    #+#             */
/*   Updated: 2023/01/26 20:01:53 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (*s != (char )c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

int	ft_strchr_idx(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return (i);
		i++;
	}
	if (uc == '\0')
		return (i);
	return (-1);
}

int	ft_strchr_set(const char *s, char *set)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (-1);
}
