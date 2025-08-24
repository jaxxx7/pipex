/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:29:25 by mhachem           #+#    #+#             */
/*   Updated: 2025/08/18 17:04:12 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse_args(char **argv, t_pipex *pipex)
{
	pipex->cmd_args[0] = ft_split(argv[2], ' ');
	pipex->cmd_args[1] = ft_split(argv[3], ' ');
	pipex->cmd_args[2] = NULL;
	if (!pipex->cmd_args[0] || !pipex->cmd_args[0][0])
	{
		perror("invalid command");
		exit(EXIT_FAILURE);
	}
}
