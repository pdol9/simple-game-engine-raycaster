/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:13:29 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 13:32:19 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(t_vars *vars, char *msg)
{
	ft_putstr_fd(msg, 1);
	if (vars)
		close_map(vars);
	exit(EXIT_FAILURE);
}

static
void	free_image(t_vars *vars, t_image *img)
{
	if (img->img_ptr)
		mlx_destroy_image(vars->mlx, img->img_ptr);
}

static
void	free_parsing(t_vars *vars)
{
	free(vars->meta.ceiling_f);
	free(vars->meta.ceiling_s);
	free(vars->meta.ceiling_t);
	free(vars->meta.floor_f);
	free(vars->meta.floor_s);
	free(vars->meta.floor_t);
	free(vars->meta.east);
	free(vars->meta.west);
	free(vars->meta.north);
	free(vars->meta.south);
}

int	close_map(t_vars *vars)
{
	int	rows;

	free_image(vars, &vars->env.north);
	free_image(vars, &vars->env.south);
	free_image(vars, &vars->env.east);
	free_image(vars, &vars->env.west);
	free_image(vars, &vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	rows = 0;
	while (rows < vars->map.size.y)
	{
		free(vars->map.layout[rows]);
		rows++;
	}
	free(vars->map.layout);
	free_parsing(vars);
	return (0);
}

int	mlx_close(void *vars)
{
	ft_putstr_fd("Quit game.\n", 1);
	close_map(vars);
	exit(0);
	return (0);
}
