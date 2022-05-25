/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:32:24 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 15:47:02 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(t_data	*pkg)
{
	int	status;

	close(pkg->fd[1]);
	dup2(pkg->fd[0], STDIN_FILENO);
	close(pkg->fd[0]);
	waitpid(pkg->pid, &status, 0);
	if (WEXITSTATUS(status) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}

void	pipex(t_data	*pkg)
{
	dup2(pkg->infd, STDIN_FILENO);
	if (pipe(pkg->fd) == -1)
		errormsg("pipe error");
	pkg->pid = fork();
	if (pkg->pid > 0)
		parent_process(pkg);
	else
	{
		close(pkg->fd[0]);
		dup2(pkg->fd[1], STDOUT_FILENO);
		close(pkg->fd[1]);
		execve(pkg->cmd1->path, pkg->cmd1->argv, pkg->envp);
		errormsg("Exec failure");
	}
	dup2(pkg->outfd, STDOUT_FILENO);
	execve(pkg->cmd2->path, pkg->cmd2->argv, pkg->envp);
	errormsg("Exec failure");
}
