/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:33:38 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 17:03:50 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_scan_same(t_vars *vars, char *line)
{
	if (line[0] == 'N')
		vars->meta.check_north++;
	if (line[0] == 'S')
		vars->meta.check_south++;
	if (line[0] == 'E')
		vars->meta.check_east++;
	if (line[0] == 'W')
		vars->meta.check_west++;
	if (line[0] == 'C')
		vars->meta.check_ceiling++;
	if (line[0] == 'F')
		vars->meta.check_floor++;
	ft_finalcheck(vars);
}

void	ft_reset_checkers(t_vars *vars)
{
	vars->meta.check_north = 0;
	vars->meta.check_south = 0;
	vars->meta.check_east = 0;
	vars->meta.check_west = 0;
	vars->meta.check_ceiling = 0;
	vars->meta.check_floor = 0;
}

void	ft_checkfor_doubles(t_vars *vars, char **argv)
{
	int		fd;
	char	*line;

	ft_reset_checkers(vars);
	fd = open(argv[1], O_RDONLY, 0644);
	line = get_next_line(fd);
	while (line)
	{
		ft_scan_same(vars, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	ft_checkrightline(char *line)
{
	if (line[0] == ' ' || line[0] == '1')
		return (0);
	else
		error(NULL, "Error\nCheck your map file input\n");
	return (1);
}

int	ft_init_game(t_vars *vars, char **argv)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	vars->map.layout = ft_malloc_zero(sizeof(char *), (vars->map.size.y));
	rows = vars->meta.firstrow;
	fd = open(argv[1], O_RDONLY, 0644);
	while (--rows >= 0)
	{
		line = get_next_line(fd);
		free(line);
	}
	rows = 0;
	line = get_next_line(fd);
	while (line != NULL && ft_checkrightline(line) == 0)
	{
		vars->map.layout[rows] = line;
		line = get_next_line(fd);
		rows++;
	}
	close(fd);
	check_layout(vars);
	return (0);
}
