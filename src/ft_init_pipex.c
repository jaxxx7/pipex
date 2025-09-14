/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:48:53 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 15:40:48 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	ft_init_pipex(void)
{
	t_pipex	pipex;
	
	pipex.infile = NULL;
	pipex.outfile = NULL;
	pipex.fd_infile = -1;
	pipex.fd_outfile = -1;
	pipex.cmd_paths = malloc(sizeof(char *) * 3);
	if (!pipex.cmd_paths)
	{
		perror("malloc failed for cmd_paths");
		exit(EXIT_FAILURE);
	}
	pipex.cmd_paths[0] = NULL;
	pipex.cmd_paths[1] = NULL;
	pipex.cmd_paths[2] = NULL;
	pipex.cmd_args = malloc(sizeof(char **) * 3);
	if (!pipex.cmd_args)
	{
		free(pipex.cmd_paths);
		perror("malloc failed for cmd_args");
		exit(EXIT_FAILURE);
	}
	pipex.cmd_args[0] = NULL;
	pipex.cmd_args[1] = NULL;
	pipex.cmd_args[2] = NULL;
	return (pipex);
}
