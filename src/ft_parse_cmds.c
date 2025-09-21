/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:49:14 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/21 13:24:06 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*find_cmd_path(char *cmd, char **paths)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

static void	check_cmd_args(char **args, char **paths)
{
	if (!args[0] || !args[0][0])
	{
		ft_free_split(paths);
		exit(EXIT_FAILURE);
	}
}

static char	*get_cmd_path(char **args, char **paths)
{
	char	*path;

	path = find_cmd_path(args[0], paths);
	if (!path)
	{
		ft_free_split(paths);
		exit(EXIT_FAILURE);
	}
	return (path);
}

t_pipex	ft_parse_cmds(t_pipex pipex, char **envp)
{
	char	*path_line;
	char	**paths;
	int		j;

	path_line = get_path_line(envp);
	if (!path_line)
	{
		ft_cleanup(&pipex);
		exit(EXIT_FAILURE);
	}
	paths = ft_split(path_line, ':');
	j = 0;
	while (j < 2)
	{
		check_cmd_args(pipex.cmd_args[j], paths);
		pipex.cmd_paths[j] = get_cmd_path(pipex.cmd_args[j], paths);
		j++;
	}
	ft_free_split(paths);
	return (pipex);
}
