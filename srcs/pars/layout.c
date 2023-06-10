/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:58:22 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 20:23:25 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_objects(t_vars *vars)
{
	int		rw;
	int		cl;
	int		val;
	char	**lo;

	rw = 0;
	val = 0;
	lo = vars->map.layout;
	while (rw++ < (vars->map.size.y - 1))
	{
		cl = 0;
		while (cl < (vars->map.size.x - 1))
		{
			if (lo[rw][cl] == 'E' || lo[rw][cl] == 'W' \
				|| lo[rw][cl] == 'S' || lo[rw][cl] == 'N')
				val++;
			if (lo[rw][cl + 1] != '\n' && lo[rw][cl + 1] != '\0')
				cl++;
			else
				break ;
		}
	}
	if (val == 0 || val > 1)
		error(NULL, "Error\n CHeck your Player Spawning points\n");
	return (0);
}

int	ft_check_surroundings(char **lo, int r, int c)
{
	int	checker;

	checker = 0;
	if (lo[r + 1][c] == ' ' || lo[r + 1][c] == '\n')
		checker = 1;
	if (lo[r - 1][c] == ' ' || lo[r - 1][c] == '\n')
		checker = 1;
	if (lo[r][c - 1] == ' ' || lo[r][c - 1] == '\n')
		checker = 1;
	if (lo[r][c + 1] == ' ' || lo[r][c + 1] == '\n' \
		|| lo[r][c + 1] == '\0')
		checker = 1;
	if (lo[r + 1][c + 1] == ' ' || lo[r + 1][c + 1] == '\n')
		checker = 1;
	if (lo[r - 1][c - 1] == ' ' || lo[r - 1][c - 1] == '\n')
		checker = 1;
	if (lo[r + 1][c - 1] == ' ' || lo[r + 1][c - 1] == '\n')
		checker = 1;
	if (lo[r - 1][c + 1] == ' ' || lo[r - 1][c + 1] == '\n' \
		|| lo[r][c + 1] == '\0')
		checker = 1;
	return (checker);
}

int	ft_checkmiddle(t_vars *vars, char **layout, int rows, int col)
{
	int	checker;

	checker = 0;
	while (col < vars->map.size.x - 1)
	{
		if (layout[rows][col] == '0' || layout[rows][col] == 'N' \
			|| layout[rows][col] == 'S' || layout[rows][col] == 'E' \
			|| layout[rows][col] == 'W')
			checker = ft_check_surroundings(layout, rows, col);
		if (checker == 1)
			error(NULL, "Error\nCheck your side walls\n");
		if (layout[rows][col + 1] != '\n' && layout[rows][col + 1] != '\0')
			col++;
		else
			break ;
	}
	return (0);
}

int	ft_checkfirstandlast(t_vars *vars, int rows, int columns)
{
	while (vars->map.layout[rows][columns] != '\n' \
			&& vars->map.layout[rows][columns] != '\0')
	{
		if (vars->map.layout[rows][columns] == ' ')
			columns++;
		if (vars->map.layout[rows][columns] == '1')
			columns++;
		if (vars->map.layout[rows][columns] != '1' &&
			vars->map.layout[rows][columns] != ' ' &&
			vars->map.layout[rows][columns] != '\n' &&
			vars->map.layout[rows][columns] != '\0')
			error(NULL, "Error\nPlease check upper and lower walls.\n");
	}
	return (0);
}

int	check_walls(t_vars *vars)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = 0;
	while (rows < vars->map.size.y)
	{
		if (rows == 0 || rows == (vars->map.size.y - 1))
			ft_checkfirstandlast(vars, rows, columns);
		if (rows != 0 && rows != (vars->map.size.y - 1))
			ft_checkmiddle(vars, vars->map.layout, rows, columns);
		if ((rows + 1) < vars->map.size.y)
			rows++;
		else
			break ;
	}
	return (0);
}
