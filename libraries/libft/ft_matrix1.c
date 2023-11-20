/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:08:01 by hbalasan          #+#    #+#             */
/*   Updated: 2023/10/29 23:05:35 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

char	**ft_dup_matrix(char **m)
{
	char	**matrix;
	int		row;
	int		i;

	i = 0;
	row = ft_matrixlen(m);
	matrix = malloc(sizeof(char *) * (row + 1));
	if (!matrix)
		return (NULL);
	while (m[i])
	{
		matrix[i] = ft_strdup(m[i]);
		if (!matrix[i])
		{
			ft_free_matrix(&matrix);
			return (NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_extend_matrix(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_matrixlen(in);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (in);
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_matrix(&in);
			ft_free_matrix(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_matrix(&in);
	return (out);
}

char	**ft_matrix_replace(char ***big, char **small, int n)
{
	char	**temp;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || n < 0 || n >= ft_matrixlen(*big))
		return (NULL);
	temp = ft_calloc(ft_matrixlen(*big) + ft_matrixlen(small), sizeof(char *));
	while (temp && big[0][++i[0]])
	{
		if (i[0] != n)
			temp[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				temp[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_matrix(big);
	*big = temp;
	return (*big);
}

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m && m[0] && m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	if (m)
	{
		free(m[0]);
		*m = NULL;
	}
}
