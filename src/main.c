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
		errormsg("enter more arguments");
		return (0); // print help page in this case
	}
	pkg = parsing(argv, argc, envp);
	pipex(pkg);
	return (0);
}

