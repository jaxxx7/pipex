/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:00:35 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 15:40:17 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5 && (argv[2][0] != '\0' && argv[3][0] != '\0'))
	{
		pipex = ft_init_pipex();
		ft_check_args(argv, argc, &pipex);
		ft_parse_args(argv, &pipex);
		pipex = ft_parse_cmds(pipex, envp);
		if (pipex.cmd_args == NULL)
		{
			ft_cleanup(&pipex);
			return (0);
		}
		ft_exec(pipex);
		(void)argv;
		(void)argc;
		ft_cleanup(&pipex);
	}
	return (0);
}
