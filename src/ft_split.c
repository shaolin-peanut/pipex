/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:12:30 by sbars             #+#    #+#             */
/*   Updated: 2021/11/03 15:12:33 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isalnum(int c)
{
	if ((((c > 64) & (c < 91)) || ((c > 96) & (c < 123)))
		|| ((c > 47) & (c < 58)))
		return (1);
	return (0);
}

int	count_strings(char const *s2, char sep)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == sep && (ft_isalnum(s2[i + 1])))
			count++;
		i++;
	}
	return (count);
}

int	ft_substrlen(char const *s3, char sep, int start)
{
	int	count;

	count = 0;
	while (s3[start])
	{
		if ((start == 0 && s3[start] != sep)
			|| (s3[start] != sep && s3[start - 1] == sep))
		{
			while (s3[start] && s3[start++] != sep)
				count++;
			return (count);
		}
		++start;
	}
	return (count);
}

char	**ft_split(char *s1, char c, t_data	*pkg)
{
	char	**tab;
	int		i;
	int		tabs;

	(void) pkg;
	i = -1;
	tabs = -1;
	if (s1 == NULL)
		return (NULL);
	tab = malloc((count_strings(s1, c)) * sizeof(char *));
	if (tab)
	{
		while (s1[++i])
		{
			if ((i == 0 && s1[i] != c) || (s1[i] != c && s1[i - 1] == c))
			{
				tab[++tabs] = malloc(sizeof(char) * ft_substrlen(s1, c, i) + 1);
				if (tab[tabs])
					ft_strlcpy(tab[tabs], (s1 + i), ft_substrlen(s1, c, i) + 1);
			}
		}
		tab[++tabs] = NULL;
	}
	else
		return (NULL);
	return (tab);
}
