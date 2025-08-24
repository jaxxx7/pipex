/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:27:48 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/24 18:34:33 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_pipex pipex)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(pipex.fd_infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		if (!pipex.cmd_paths[0])
			exit(EXIT_FAILURE);
		execve(pipex.cmd_paths[0], pipex.cmd_args[0], NULL);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex.fd_outfile, STDOUT_FILENO);
		if (!pipex.cmd_paths[1])
			exit(EXIT_FAILURE);
		execve(pipex.cmd_paths[1], pipex.cmd_args[1], NULL);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
