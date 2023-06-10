/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:09:53 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 18:03:54 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_finalcheck(t_vars *vars)
{
	if (vars->meta.check_north > 1 || vars->meta.check_south > 1 \
		|| vars->meta.check_east > 1 || vars->meta.check_west > 1 \
		|| vars->meta.check_ceiling > 1 || vars->meta.check_floor > 1)
		error(NULL, "Error\n Check the input textures and RGBs\n");
}

void	ft_bugreport_end(char *line, int i)
{
	if (line[i] != '\n' && line[i] != '\0')
		error(NULL, "Error\n Check end of RGB input rows\n");
}

int	check_layout(t_vars *vars)
{
	check_walls(vars);
	check_objects(vars);
	return (0);
}
