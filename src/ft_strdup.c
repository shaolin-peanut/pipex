/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:27:22 by sbars             #+#    #+#             */
/*   Updated: 2022/05/05 16:27:35 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = -1;
	copy = malloc (sizeof(char) * ft_strlen((char *)s1) + 1);
	if (copy)
	{
		while (s1[++i])
			copy[i] = s1[i];
		copy[i] = '\0';
	}
	return (copy);
}
