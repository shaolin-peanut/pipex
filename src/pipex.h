/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:25:45 by sbars             #+#    #+#             */
/*   Updated: 2022/05/04 15:29:26 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
// check before including for good
#include <stdio.h>
#include <stdlib.h>

typedef	struct s_cmd	t_cmd;

struct s_cmd
{
	char	*path;
	char	**argv;
};

typedef struct s_data
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**envp;
	char	**paths;
	int		fd[2];
	int		infd;
	int		outfd;
	pid_t	pid;
}	t_data;

// src/main.c
void	pipex(t_data	*pkg);
// src/parse_ops.c
t_data	*parsing(char	**args, int	argc, char	**envp);
char	*fill_infile(int fd);
t_data	*init_data(t_data	*pkg, char	**envp);
t_cmd	*init_cmd(char	**args, t_data	*pkg);
// src/check.c
void	file_access_check(int count, char **args);
void	cmds_exe_check();
// src/process.c
void	child_launchpad(t_data *pkg);
void	parent_launchpad(t_data	*pkg, int	info);
// errormsg.c
void	errormsg(char *str);
// utils.c
char	*find_path(char	*cmd_name, t_data	*pkg);

// FOREIGNERS
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *s1, char c);
int		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char	*s1);
char	*ft_strchr(char	*string, char c);
