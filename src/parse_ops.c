/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:35:03 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 14:19:55 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// FUNCTION COUNT: 4
#include "pipex.h"

// Parse argv to put infile and cmds properly stored for later use in t_data pkg
t_data	*argv_parse(t_data *pkg, char **args, int argc)
{
	if ((pkg->infd = open(args[1], O_RDONLY)) == -1)
		errormsg("infile open error");
	if ((pkg->outfd = open(args[argc - 1], O_RDWR)) == -1)
		errormsg("outfile open error");
	pkg->cmd1 = init_cmd(ft_split(args[2], ' '), pkg);
	pkg->cmd2 = init_cmd(ft_split(args[3], ' '), pkg);
	return (pkg);
}

t_cmd	*init_cmd(char **args, t_data	*pkg)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(1 * sizeof(cmd));
	if (!cmd)
		errormsg("cmd malloc error, parse_ops.c:68");
	cmd->path = find_path(args[0], pkg);
	cmd->argv = (char	**)malloc(1 * sizeof(args));
	if (!cmd->argv)
		errormsg("pkg->argv malloc error");
	cmd->argv = args;

	return (cmd);
}
// Where it starts...
// Create pkg
// Redirect to every other
t_data	*parsing(char **args, int argc, char **envp)
{
	t_data	*pkg;

	pkg = NULL;
	pkg = init_data(pkg, envp);
	argv_parse(pkg, args, argc);
	return (pkg);
}

// Find cmd path in child process, by testing every cmd+path with exec (if error, retry with other path, if all paths tried, return error).
char	**paths_finder(char	**env)
{
	int	i;
	//char	**line;

	i = -1;
	//line = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				//line = ft_split(env[i], '=');	
				return(ft_split(*(ft_split(env[i], '=') + 1), ':'));
				//free(line);
				//line = NULL;
		}
	}
	return (NULL);
}

t_data	*init_data(t_data *pkg, char **envp)
{
	pkg = (t_data *)malloc(1 * sizeof(t_data));
	if (!pkg)
		errormsg("pkg malloc error");
	pkg->cmd1 = 0;
	pkg->cmd2 = 0;
	pkg->envp = 0;
	pkg->envp = envp;
	pkg->paths = 0;
	pkg->paths = paths_finder(envp);
	pkg->pid = 0;
	pkg->fd[0] = 0;
	pkg->fd[1] = 0;
	pkg->outfd = 0;
	pkg->infd = 0;
	return (pkg);
}

