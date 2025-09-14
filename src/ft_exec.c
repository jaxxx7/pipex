/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:27:48 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 13:06:08 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_child(char *cmd_path, char **cmd_args, int fd_in, int fd_out)
{
	if (!cmd_path)
		exit(EXIT_FAILURE);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	execve(cmd_path, cmd_args, NULL);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

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
		exec_child(pipex.cmd_paths[0], pipex.cmd_args[0],
			pipex.fd_infile, fd[1]);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		exec_child(pipex.cmd_paths[1], pipex.cmd_args[1],
			fd[0], pipex.fd_outfile);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
