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

void	pipex(t_data	*pkg)
{
	int fd[2];
	int status;

	dup2(pkg->infd, STDIN_FILENO);//infile fd is set as stdin
	if (pipe(fd) == -1)
		errormsg("pipe error");
	pkg->pid = fork();
	if (pkg->pid > 0)// we are in parent process
	{	
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);// pipe read is input for next exec
		close(fd[0]);
		waitpid(pkg->pid, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}
	else // we are in the child process
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(pkg->cmd1->path, pkg->cmd1->argv, pkg->envp);
		errormsg("Command 1 not found, or exec failure");
	}
	dup2(pkg->outfd, STDOUT_FILENO);
	execve(pkg->cmd2->path, pkg->cmd2->argv, pkg->envp);
	errormsg("Command 2 not found, or exec failure");
	exit(EXIT_SUCCESS);
}

/*void	child_launchpad(t_data *pkg)
{
	usleep(1);
	int	ret;

	ret = 0;

	printf("I AM A CHILD\n");
	//printf("pkg->cmd->path: %s\n", pkg->cmd->path);
	//printf("pkg->cmd->argv[0]: %s\n", pkg->cmd->argv[1]);
	//printf("pkg->cmd->argv[1]: %s\n", pkg->cmd->argv[1]);
	close(pkg->fd[0]);
	dup2(pkg->fd[1], STDOUT_FILENO);
	close(pkg->fd[1]);
	if ((ret = execve(pkg->cmd->path, pkg->cmd->argv, pkg->envp) == -1))
			errormsg("exec failure");
}*/

void	parent_launchpad(t_data	*pkg, int info)
{
	int		wstatus;

	printf("I AM A PARENT\n");
	close(pkg->fd[1]);
	if (info == 1) // redirect read end of pipe to input of next exec
		dup2(pkg->fd[0], STDIN_FILENO);
	else if (info == 0) // redirect read of pipe to output when it's the last one
		dup2(pkg->fd[0], STDOUT_FILENO);
	close(pkg->fd[0]);
	// wait for child process to terminate, before continuing program execution
	waitpid(pkg->pid, &wstatus, 0);
}

