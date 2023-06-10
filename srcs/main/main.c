/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:45:48 by mluik             #+#    #+#             */
/*   Updated: 2022/11/30 20:22:04 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = ft_init_vars();
	ft_check_map(argc, argv);
	ft_parse_map(&vars, argv);
	position_player(&vars);
	init_mlx_data(&vars);
	fov_rendering(&vars);
	mlx_hook(vars.win, 2, 1L << 0, use_key, &vars);
	mlx_hook(vars.win, 17, 1L << 2, mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
