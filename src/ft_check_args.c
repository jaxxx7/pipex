/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:37:09 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/24 18:33:38 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_args(char **argv, int argc, t_pipex *pipex)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->fd_infile = open(pipex->infile, O_RDONLY);
	if (pipex->fd_infile == -1)
	{
		perror("open");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->fd_outfile = open(pipex->outfile, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_outfile == -1)
	{
		perror("open outfile");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
}
