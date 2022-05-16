/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:27:38 by sbars             #+#    #+#             */
/*   Updated: 2022/04/29 13:30:22 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	file_access_check(int count, char **args)
{
	int	i;


	i = 2;
	printf("[LOCATION]: check.c:file_access_check()\n");
	// if (args[1] == "heredoc"
	// do appropriate function
	if	(access(args[1], R_OK) == -1)
	{
		errormsg("infile");
		exit(EXIT_FAILURE);
	}
	if	(access(args[count - 1], W_OK) == -1 || access(args[count - 1], R_OK) == -1)
	{
		errormsg("outfile");
		exit(EXIT_FAILURE);
	}
}*/

/*void	cmds_exe_check()
{
	char **mypaths;
	char **mycmdargs;// retrieve the line PATH from envp
	PATH_from_envp = ft_substr(envp ....);
	mypaths = ft_split(PATH_from_envp, ":"); // see section 4 for a
                                            small note[0]
	mycmdargs = ft_split(ag[2], " ");// in your child or parent processint  i;
	char *cmd;i = -1;
	while (mypaths[++i])
	{
    	cmd = ft_join(mypaths[i], ag[2]); // protect your ft_join
    	execve(cmd, mycmdargs, envp); // if execve succeeds, it exits
    	// errormsg("Error"); <- add errormsg to debug
    	free(cmd) // if execve fails, we free and we try a new path
	}
	return (EXIT_FAILURE); 
}
FROM: https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
*/
