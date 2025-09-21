/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:49:14 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/21 11:07:00 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

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

t_pipex	ft_parse_cmds(t_pipex pipex, char **envp)
{
	char	*path_line;
	char	**paths;
	int		j;

	path_line = get_path_line(envp);
	paths = ft_split(path_line, ':');
	j = 0;
	while (j < 2)
	{
		if (!pipex.cmd_args[j][0] || !pipex.cmd_args[j][0][0])
		{
			ft_free_split(paths);
			exit(EXIT_FAILURE);
		}
		pipex.cmd_paths[j] = find_cmd_path(pipex.cmd_args[j][0], paths);
		if (!pipex.cmd_paths[j])
		{
			ft_free_split(paths);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	ft_free_split(paths);
	return (pipex);
}
