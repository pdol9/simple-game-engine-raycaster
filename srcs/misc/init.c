/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:38:05 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 16:38:51 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_meta(t_vars *vars, char *line)
{
	ft_check_order(vars, line);
	ft_parse_textures(vars, line, 'N', 'O');
	ft_parse_textures(vars, line, 'S', 'O');
	ft_parse_textures(vars, line, 'W', 'E');
	ft_parse_textures(vars, line, 'E', 'A');
	ft_parse_colors(vars, line);
}

void	ft_scan_size(char *line, t_vars *vars, int fd, int rows)
{
	int	checker;
	int	len;

	checker = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (line[0] == ' ' || line[0] == '1')
		{
			if (checker == 0)
			{
				vars->meta.firstrow = rows;
				checker = 1;
			}
			if (len >= vars->map.size.x)
				vars->map.size.x = len;
			vars->map.size.y++;
		}
		free(line);
		line = get_next_line(fd);
		rows++;
	}
}

int	ft_get_mapsize(t_vars *vars, char **argv)
{
	int		fd;
	int		rows;
	char	*line;

	line = NULL;
	rows = 1;
	fd = open(argv[1], O_RDONLY, 0644);
	if (fd == -1)
		error(NULL, "Error\n No map file found\n");
	line = get_next_line(fd);
	while (ft_checkcheck(vars) != 1 && line)
	{
		ft_parse_meta(vars, line);
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	free(line);
	ft_scan_size(line, vars, fd, rows);
	close(fd);
	return (0);
}

void	ft_parse_map(t_vars *vars, char **argv)
{
	ft_get_mapsize(vars, argv);
	ft_init_game(vars, argv);
	ft_checkfor_doubles(vars, argv);
	init_colors_f(vars);
	init_colors_c(vars);
}

int	ft_check_map(int argc, char **argv)
{
	if (argc < 2)
		error(NULL, "Error\n Wrong arguments.\n");
	if (argc > 2)
		error(NULL, "Error\n Too many arguments.\n");
	if (ft_strstr(argv[1], ".cub") == NULL)
		error(NULL, "Error\n Check file extension .cub\n");
	return (0);
}
