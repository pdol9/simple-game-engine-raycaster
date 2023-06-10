/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:21:14 by pdolinar          #+#    #+#             */
/*   Updated: 2022/11/29 20:49:41 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < vars->display.size.y / 2)
	{
		color = vars->env.c;
		x = 0;
		while (x < vars->display.size.x)
			put_pixel(&(vars->img), x++, y, color);
		y++;
	}
	while (y < vars->display.size.y)
	{
		color = vars->env.f;
		x = 0;
		while (x < vars->display.size.x)
			put_pixel(&(vars->img), x++, y, color);
		y++;
	}
}

void	fov_rendering(t_vars *vars)
{
	int	x;

	background(vars);
	x = 0;
	while (x < vars->display.size.x)
	{
		ray_casting(vars, &vars->display.rays, x);
		grid_scanning(vars, &vars->display.rays);
		wall_mapping(vars, &vars->display.rays);
		wall_projec(vars, &vars->display.rays);
		ft_setwall(vars, &vars->display.rays);
		draw_tex(get_wall_img(&vars->env), vars, x);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
}
