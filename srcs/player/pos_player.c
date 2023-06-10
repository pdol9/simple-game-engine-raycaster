/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:39:05 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 14:43:00 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_save_dir(t_vars *vars, char pchar)
{
	if (pchar == 'N')
	{
		vars->map.pos.dir_y = -1;
		vars->map.pos.plane_x = 0.66;
		vars->map.pos.plane_y = 0;
	}
	else if (pchar == 'E')
	{
		vars->map.pos.dir_x = 1;
		vars->map.pos.plane_y = 0.66;
		vars->map.pos.plane_x = 0;
	}
	else if (pchar == 'S')
	{
		vars->map.pos.dir_y = 1;
		vars->map.pos.plane_y = 0;
		vars->map.pos.plane_x = -1;
	}
	else if (pchar == 'W')
	{
		vars->map.pos.dir_x = -1;
		vars->map.pos.plane_x = 0;
		vars->map.pos.plane_y = -1;
	}
	return (0);
}

void	position_player(t_vars *vars)
{
	int		rw;
	int		cl;
	char	**lo;

	rw = 0;
	cl = 0;
	lo = vars->map.layout;
	while (cl < (vars->map.size.x - 2) && rw < vars->map.size.y)
	{
		if (lo[rw][cl] == 'N' || lo[rw][cl] == 'E' \
			|| lo[rw][cl] == 'S' || lo[rw][cl] == 'W')
		{
			vars->map.pos.x = (double)cl + 0.5;
			vars->map.pos.y = (double)rw + 0.5;
			ft_save_dir(vars, lo[rw][cl]);
			lo[rw][cl] = '0';
		}
		if (lo[rw][cl + 1] != '\n' && lo[rw][cl + 1] != '\0')
			cl++;
		if ((lo[rw][cl + 1] == '\n' || lo[rw][cl + 1] == '\0'))
		{
			rw++;
			cl = 0;
		}
	}
}
