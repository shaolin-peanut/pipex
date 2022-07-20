/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:24:25 by sbars             #+#    #+#             */
/*   Updated: 2022/05/05 10:39:04 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*pkg;

	if (argc < 5)
	{
		write(1, "Usage:\n./pipex infile \"cmd1 arg1\" \"cmd2 arg1\" outfile\"\n", 55);
		exit(EXIT_FAILURE);
	}
	pkg = parsing(argv, argc, envp);
	pipex(pkg);
	return (0);
}
