/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:00:35 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/21 11:11:07 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5 && !ft_zero(argv))
	{
		pipex = ft_init_pipex();
		ft_check_args(argv, argc, &pipex);
		ft_parse_args(argv, &pipex);
		pipex = ft_parse_cmds(pipex, envp);
		ft_exec(pipex);
		ft_cleanup(&pipex);
	}
	return (0);
}
