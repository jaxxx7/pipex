/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:05:10 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/21 10:36:41 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd_paths(char **cmd_paths)
{
	int	i;

	i = 0;
	if (!cmd_paths)
		return ;
	while (cmd_paths[i])
		free(cmd_paths[i++]);
	free(cmd_paths);
}

static void	free_cmd_args(char ***cmd_args)
{
	int	i;
	int	j;

	if (!cmd_args)
		return ;
	i = 0;
	while (cmd_args[i])
	{
		j = 0;
		while (cmd_args[i][j])
			free(cmd_args[i][j++]);
		free(cmd_args[i++]);
	}
	free(cmd_args);
}

void	ft_cleanup(t_pipex *pipex)
{
	if (!pipex)
		return ;
	free_cmd_paths(pipex->cmd_paths);
	free_cmd_args(pipex->cmd_args);
	if (pipex->fd_infile != -1)
		close(pipex->fd_infile);
	if (pipex->fd_outfile != -1)
		close(pipex->fd_outfile);
}
