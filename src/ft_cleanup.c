/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:05:10 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/24 15:18:30 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cleanup(t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex->cmd_paths)
	{
		i = 0;
		while (pipex->cmd_paths[i])
		{
			free(pipex->cmd_paths[i]);
			i++;
		}
		free(pipex->cmd_paths);
	}
	if (pipex->cmd_args)
	{
		i = 0;
		while (pipex->cmd_args[i])
		{
			j = 0;
			while (pipex->cmd_args[i][j])
			{
				free(pipex->cmd_args[i][j]);
				j++;
			}
			free(pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->fd_infile != -1)
		close(pipex->fd_infile);
	if (pipex->fd_outfile != -1)
		close(pipex->fd_outfile);
}
