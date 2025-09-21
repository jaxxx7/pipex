/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:26:06 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/21 11:12:42 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_zero(char **argv)
{
	int	i;

	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] != ' ')
			break ;
		i++;
	}
	if (!argv[2][i])
		return (1);
	i = 0;
	while (argv[3][i])
	{
		if (argv[3][i] != ' ')
			break ;
		i++;
	}
	if (!argv[3][i])
		return (1);
	return (0);
}
