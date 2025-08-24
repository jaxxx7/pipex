/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:49:14 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/24 18:34:07 by mhachem          ###   ########.fr       */
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
	return (0);
}

t_pipex	ft_parse_cmds(t_pipex pipex, char **envp)
{
	char	*path_tmp;
	char	**path_split;
	int		i;
	char	*tmp;
	int		j;

	path_tmp = get_path_line(envp);
	path_split = ft_split(path_tmp, ':');
	i = 0;
	j = 0;
	while (j < 2)
	{
		i = 0;
		while (path_split[i])
		{
			tmp = ft_strjoin(path_split[i], "/");
			path_tmp = ft_strjoin(tmp, pipex.cmd_args[j][0]);
			free(tmp);
			if (access(path_tmp, X_OK) == 0)
			{
				pipex.cmd_paths[j] = path_tmp;
				break ;
			}
			free(path_tmp);
			i++;
		}
		j++;
	}
	i = 0;
	while (path_split[i])
		free(path_split[i++]);
	free(path_split);
	return (pipex);
}
