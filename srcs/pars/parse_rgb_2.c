/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:04:30 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 18:01:58 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_savestring(t_vars *vars, int check, int i, char *line)
{
	int	j;
	int	k;

	k = 0;
	k = ft_count_comma(i, line);
	j = 0;
	while (k != 0)
	{
		if (check == 0)
			vars->meta.floor_f[j] = line[i];
		if (check == 1)
			vars->meta.floor_s[j] = line[i];
		if (check == 2)
			vars->meta.floor_t[j] = line[i];
		if (check == 3)
			vars->meta.ceiling_f[j] = line[i];
		if (check == 4)
			vars->meta.ceiling_s[j] = line[i];
		if (check == 5)
			vars->meta.ceiling_t[j] = line[i];
		k--;
		j++;
		i++;
	}
	return (j);
}

int	ft_save_ceiling(t_vars *vars, int check, int i, char *line)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_comma(i, line);
	if (k == 0 || k >= 4)
		error(NULL, "Error\n Check your RGB lines\n");
	if (check == 3)
		vars->meta.ceiling_f = ft_malloc_zero(sizeof(char *), k);
	if (check == 4)
		vars->meta.ceiling_s = ft_malloc_zero(sizeof(char *), k);
	if (check == 5)
		vars->meta.ceiling_t = ft_malloc_zero(sizeof(char *), k);
	j = ft_savestring(vars, check, i, line);
	return (j);
}

int	parse_ceiling(t_vars *vars, char *line)
{
	int	i;
	int	check;

	i = 1;
	i += ft_findfirst(line, i);
	check = 3;
	if (i == 1)
		error(NULL, "Error\nCheck your data input in map\n");
	while (check >= 3 && check < 6)
	{
		i += ft_save_ceiling(vars, check, i, line);
		if (check == 5)
			ft_bugreport_end(line, i);
		i++;
		check++;
	}
	return (1);
}

int	ft_save_floor(t_vars *vars, int check, int i, char *line)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	k = ft_count_comma(i, line);
	if (k == 0 || k >= 4)
		error(NULL, "Error\n Check your RGB lines\n");
	if (check == 0)
		vars->meta.floor_f = ft_malloc_zero(sizeof(char *), k);
	if (check == 1)
		vars->meta.floor_s = ft_malloc_zero(sizeof(char *), k);
	if (check == 2)
		vars->meta.floor_t = ft_malloc_zero(sizeof(char *), k);
	j = ft_savestring(vars, check, i, line);
	return (j);
}

int	parse_floor(t_vars *vars, char *line)
{
	int	i;
	int	check;

	i = 1;
	i += ft_findfirst(line, i);
	check = 0;
	if (i == 1)
		error(NULL, "Error\nCheck your data input in map\n");
	while (check < 3)
	{
		i += ft_save_floor(vars, check, i, line);
		if (check == 2)
			ft_bugreport_end(line, i);
		i++;
		check++;
	}
	return (1);
}
