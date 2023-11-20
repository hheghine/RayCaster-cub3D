/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:17:10 by hbalasan          #+#    #+#             */
/*   Updated: 2023/01/26 18:08:59 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 && set)
	{
		i = 0;
		j = ft_strlen(s1);
		while (*(s1 + i) && ft_strchr(set, *(s1 + i)))
			i++;
		while (*(s1 + j - 1) && ft_strchr(set, *(s1 + j - 1)) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (NULL);
		else
			ft_strlcpy(str, s1 + i, j - i + 1);
		return (str);
	}
	return (NULL);
}
