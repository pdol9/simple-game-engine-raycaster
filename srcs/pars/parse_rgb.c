/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:50:30 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 17:50:00 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	return_int(char *string)
{
	int		r;
	char	*tmp;

	tmp = string;
	r = 0;
	while (*string)
	{
		if (*string < '0' || *string > '9')
			error(NULL, "Error\n Invalid RGB values.\n");
		string++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		r = r * 10 + (*tmp++ - '0');
	}
	return (r);
}

int	ft_findfirst(char *line, int start)
{
	int	i;

	i = 0;
	while (line[start] == ' ')
	{
		start++;
		i++;
	}
	return (i);
}

void	init_colors_c(t_vars *vars)
{
	int	r;
	int	g;
	int	b;

	r = return_int(vars->meta.ceiling_f);
	g = return_int(vars->meta.ceiling_s);
	b = return_int(vars->meta.ceiling_t);
	if (r > 255 || g > 255 || b > 255)
		error(NULL, "Error\n Check RGB input values\n");
	vars->env.f = (r << 16 | g << 8 | b);
}

void	init_colors_f(t_vars *vars)
{
	int	r;
	int	g;
	int	b;

	r = return_int(vars->meta.floor_f);
	g = return_int(vars->meta.floor_s);
	b = return_int(vars->meta.floor_t);
	if (r > 255 || g > 255 || b > 255)
		error(NULL, "Error\n Check RGB input values\n");
	else
		vars->env.c = (r << 16 | g << 8 | b);
}

int	ft_count_comma(int i, char *line)
{
	int	k;

	k = 0;
	while (line[i] != ',' && line[i] != '\0' && line[i] != '\n' \
			&& line[i] != '\0')
	{
		if (line[i] <= 47 || line[i] >= 58)
			error(NULL, "Error\n Check your RGB input\n");
		i++;
		k++;
	}
	return (k);
}
