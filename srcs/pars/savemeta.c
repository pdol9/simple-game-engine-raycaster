/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemeta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:58:28 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 15:56:41 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_saveeast(int i, char *line, t_vars *vars)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_char(line, i);
	if (vars->meta.check_east != 0)
		error(NULL, "Error\n Check your map input in .CUB\n");
	vars->meta.east = ft_malloc_zero(sizeof(char *), k);
	while (line[i] != '\n' && line[i] != '\0')
	{
		vars->meta.east[j] = line[i];
		i++;
		j++;
	}
	vars->meta.check_east = 1;
}

void	ft_savewest(int i, char *line, t_vars *vars)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_char(line, i);
	if (vars->meta.check_west != 0)
		error(NULL, "Error\n Check your map input in .CUB\n");
	vars->meta.west = ft_malloc_zero(sizeof(char *), k);
	while (line[i] != '\n' && line[i] != '\0')
	{
		vars->meta.west[j] = line[i];
		i++;
		j++;
	}
	vars->meta.check_west = 1;
}

void	ft_savesouth(int i, char *line, t_vars *vars)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_char(line, i);
	if (vars->meta.check_south != 0)
		error(NULL, "Error\n Check your map input in .CUB\n");
	vars->meta.south = ft_malloc_zero(sizeof(char *), k);
	while (line[i] != '\n' && line[i] != '\0')
	{
		vars->meta.south[j] = line[i];
		i++;
		j++;
	}
	vars->meta.check_south = 1;
}

void	ft_savenorth(int i, char *line, t_vars *vars)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_char(line, i);
	if (vars->meta.check_north != 0)
		error(NULL, "Error\n Check your map input in .CUB\n");
	vars->meta.north = ft_malloc_zero(sizeof(char *), k);
	while (line[i] != '\n' && line[i] != '\0')
	{
		vars->meta.north[j] = line[i];
		i++;
		j++;
	}
	vars->meta.check_north = 1;
}
