/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:38:07 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 13:52:39 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		i;

	i = -1;
	copy = malloc (sizeof(char) * ft_strlen((char *)s1) + 2);
	if (copy)
	{
		while (s1[++i])
			copy[i] = s1[i];
		copy[i] = '\0';
	}
	else
		return (NULL);
	return (copy);
}

char	*ft_strchr(char *string, char c)
{
	int	a;

	a = 0;
	while (*(string + a) != c)
	{
		if (*(string + a) == 0)
			return (NULL);
		a++;
	}
	return ((char *)(string + a));
}

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = malloc(1 * sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = (NULL);
	return (new);
}
