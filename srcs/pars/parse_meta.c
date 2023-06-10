/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:52:01 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 17:39:52 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkcheck(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->meta.check_north == 1 && vars->meta.check_south == 1 \
		&& vars->meta.check_west == 1 && vars->meta.check_east == 1 \
		&& vars->meta.check_floor == 1 && vars->meta.check_ceiling == 1)
		i = 1;
	else
		i = 0;
	return (i);
}

int	ft_check_order(t_vars *vars, char *line)
{
	if ((line[0] == '1' || line[0] == ' ') && ft_checkcheck(vars) == 0)
		error(NULL, "Error\n Check your map file\n");
	return (0);
}

int	ft_count_char(char *line, int i)
{
	int	k;

	k = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		i++;
		k++;
	}
	return (k);
}

void	ft_parse_colors(t_vars *vars, char *line)
{
	if (line[0] == 'F')
	{
		vars->meta.check_floor = parse_floor(vars, line);
		if (vars->meta.check_floor == 0)
			error(NULL, "Error\n check your RGB input\n");
	}
	if (line[0] == 'C')
	{
		vars->meta.check_ceiling = parse_ceiling(vars, line);
		if (vars->meta.check_ceiling == 0)
			error(NULL, "Error\n check your RGB input\n");
	}
}

void	ft_parse_textures(t_vars *vars, char *line, char x, char y)
{
	int	i;

	i = 0;
	if (line[i] == x && line[i + 1] == y)
	{
		i = 2;
		while (line[i] == ' ')
			i++;
		if (line[i] == '.' && line[i + 1] == '/')
		{
			if (x == 'N')
				ft_savenorth(i + 2, line, vars);
			if (x == 'S')
				ft_savesouth(i + 2, line, vars);
			if (x == 'W')
				ft_savewest(i + 2, line, vars);
			if (x == 'E')
				ft_saveeast(i + 2, line, vars);
		}
		else
			error(NULL, "Error\n check your metadata in .cub file\n");
	}
}
