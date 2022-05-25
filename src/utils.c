/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:01:44 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 13:42:44 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*find_path(char	*cmd_name, t_data	*pkg)
{
	int		i;
	int		ret;
	char	*temp_path;
	char	*temp_path2;

	i = -1;
	ret = 0;
	temp_path = NULL;
	temp_path2 = NULL;
	while (pkg->paths[++i])
	{
		temp_path = ft_strjoin(pkg->paths[i], "/");
		temp_path2 = ft_strjoin(temp_path, cmd_name);
		free(temp_path);
		temp_path = NULL;
		ret = access(temp_path2, X_OK);
		if (ret == 0)
			return (temp_path2);
		free(temp_path2);
		temp_path2 = NULL;
	}	
	errormsg("Command not found");
	return ("not found");
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concatenated;
	int		i1;
	int		i2;
	int		i;

	if (s1 && s2)
	{
		i1 = ft_strlen((char *) s1);
		i2 = ft_strlen((char *) s2);
		i = -1;
		concatenated = malloc(sizeof(*concatenated) * i2 + i1 + 1);
		if (concatenated == NULL)
			errormsg("malloc error");
		while (++i < i1)
			concatenated[i] = s1[i];
		i = -1;
		while (++i < i2)
			concatenated[i + i1] = s2[i];
		concatenated[i + i1] = '\0';
	}
	else
		return (0);
	return (concatenated);
}

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long int		srcsize;

	srcsize = ft_strlen((char *) src);
	if (dstsize < 1)
		return (srcsize);
	if (srcsize < dstsize)
	{
		ft_memcpy(dst, src, srcsize);
		dst[srcsize] = '\0';
		return (srcsize);
	}
	else
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
		return (srcsize);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	i = -1;
	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	while (++i < (int) n && (string1[i] || string2[i]))
	{
		if (string1[i] > string2[i])
			return (1);
		else if (string1[i] < string2[i])
			return (-1);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (NULL);
	if (n-- > 0)
	{
		dest = (char *) dst;
		source = (char *) src;
		while (n)
		{
			dest[n] = source[n];
			n--;
		}
		dest[n] = source[n];
	}
	return (dst);
}
