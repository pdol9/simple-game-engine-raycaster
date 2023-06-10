/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:21:14 by pdolinar          #+#    #+#             */
/*   Updated: 2022/11/29 19:32:36 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

t_image	*get_wall_img(t_texture *tex)
{
	if (tex->wallcode == 1)
		return (&(tex->west));
	else if (tex->wallcode == 2)
		return (&(tex->north));
	else if (tex->wallcode == 3)
		return (&(tex->east));
	else
		return (&(tex->south));
}

void	ft_setwall(t_vars *vars, t_graphics *rays)
{
	if (rays->step_y == -1 && rays->step_x == -1 && rays->side == 1)
		vars->env.wallcode = 2;
	else if (rays->step_y == 1 && rays->step_x == -1 && rays->side == 0)
		vars->env.wallcode = 1;
	else if (rays->step_y == -1 && rays->step_x == -1 && rays->side == 0)
		vars->env.wallcode = 1;
	else if (rays->step_y == -1 && rays->step_x == 1 && rays->side == 0)
		vars->env.wallcode = 3;
	else if (rays->step_y == 1 && rays->step_x == 1 && rays->side == 1)
		vars->env.wallcode = 4;
	else if (rays->step_y == 1 && rays->step_x == -1 && rays->side == 1)
		vars->env.wallcode = 4;
	else if (rays->step_y == -1 && rays->step_x == 1 && rays->side == 1)
		vars->env.wallcode = 2;
	else if (rays->step_y == 1 && rays->step_x == 1 && rays->side == 0)
		vars->env.wallcode = 3;
}
