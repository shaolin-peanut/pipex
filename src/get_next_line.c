/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:37:48 by sbars             #+#    #+#             */
/*   Updated: 2022/05/02 12:43:52 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	lts_to_str(t_list **buf_list, int len, char *line);

static void	free_ptr(void **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*buf_list[MAX_FD + 1];
	char			*result;
	int				templen;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf_list[fd] == NULL)
		buf_list[fd] = ft_lstnew(ft_strdup(""));
	templen = ft_strlen(buf_list[fd]->content);
	result = read_process(&buf_list[fd], buf_list[fd], templen, fd);
	return (result);
}

char	*read_process(t_list **buf_list, t_list *last, int len, int fd)
{
	char	*content;
	int		read_counter;
	t_list	*end;

	content = ft_strchr(last->content, '\n');
	if (content != NULL)
	{
		read_counter = ft_strlen(content + 1);
		return (concat_ops(read_counter, len, &buf_list[0]));
	}
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (content == NULL)
		return (NULL);
	read_counter = read(fd, content, BUFFER_SIZE);
	if (read_counter <= 0)
	{
		free_ptr((void **)&content);
		return (concat_ops(read_counter, len, &buf_list[0]));
	}
	else
		len += read_counter;
	content[read_counter] = 0;
	end = ft_lstnew(content);
	last->next = end;
	return (read_process(&buf_list[0], end, len, fd));
}

char	*concat_ops(int end, int len, t_list	**buf_list)
{
	int		strlen;
	char	*output;

	output = NULL;
	if (len <= 0)
	{
		free_ptr((void **)&buf_list[0]->content);
		free_ptr((void **)buf_list);
		return (NULL);
	}
	strlen = len - end;
	output = (char *) malloc(strlen + 1 * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[strlen] = 0;
	lts_to_str(buf_list, strlen, output);
	return (output);
}

static void	lts_to_str(t_list **buf_list, int len, char *line)
{
	t_list	*tmp;
	char	*content;
	int		a;

	a = 0;
	while (a < len)
	{
		tmp = buf_list[0];
		content = (char *)tmp->content;
		while (*content != 0 && a < len)
		{
			line[a] = *content;
			content++;
			a++;
		}
		if (*content != 0)
			buf_list[0]->next = ft_lstnew(ft_strdup(content));
		buf_list[0] = buf_list[0]->next;
		free_ptr((void **)&tmp->content);
		free_ptr((void **)&tmp);
	}
}
