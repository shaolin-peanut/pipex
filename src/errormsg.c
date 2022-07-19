/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:30:18 by tgrivel           #+#    #+#             */
/*   Updated: 2022/05/04 10:53:45 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	errormsg(char *str, t_data  *pkg)
{
	if (str == 0)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
	close(pkg->infd);
	close(pkg->outfd);
	free(pkg->paths);
	if (pkg->cmd1 != NULL)
	{
		free(pkg->cmd1->argv);
		free(pkg->cmd1);
	}
	if (pkg->cmd2 != NULL)
	{
		free(pkg->cmd2->argv);
		free(pkg->cmd2);
	}
	free(pkg);
	exit(EXIT_FAILURE);
}
