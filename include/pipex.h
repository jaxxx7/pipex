/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:51:07 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 15:40:36 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmd_paths;
	char	***cmd_args;
	int		fd_infile;
	int		fd_outfile;
}				t_pipex;

t_pipex	ft_init_pipex(void);
void	ft_check_args(char **argv, int argc, t_pipex *pipex);
void	ft_parse_args(char **argv, t_pipex *pipex);
t_pipex	ft_parse_cmds(t_pipex pipex, char **envp);
void	ft_exec(t_pipex pipex);
char	*get_path_line(char **envp);
void	ft_cleanup(t_pipex *pipex);
void	ft_free_split(char **split);

#endif