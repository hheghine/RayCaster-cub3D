/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:23:26 by hbalasan          #+#    #+#             */
/*   Updated: 2023/02/21 20:51:32 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = (char *)malloc(len_1 + len_2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_1 || i < len_2)
	{
		if (i < len_1)
			s3[i] = s1[i];
		if (i < len_2)
			s3[i + len_1] = s2[i];
		i++;
	}
	s3[len_1 + len_2] = '\0';
	return (s3);
}
