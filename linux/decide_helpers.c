/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:39:28 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 16:01:41 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_scale_map(int key, t_vars *vars)
{
	if (key == PL_KEY)
	{
		vars->move.scale += 1;
		ft_print_new(vars);
	}
	else
	{
		vars->move.scale -= 1;
		if (vars->move.scale > 0)
			ft_print_new(vars);
		else
		{
			vars->move.scale = 1;
			mlx_string_put(vars->mlx, vars->win, 1000, 240, 0xFFFFFF, \
			"Error: no zoom in");
		}
	}
}

void	ft_move_map(int k, t_vars *vars)
{
	if (k == RIGHT_KEY)
		vars->move.x += 10;
	else if (k == LEFT_KEY)
		vars->move.x -= 10;
	else if (k == UP_KEY)
		vars->move.y -= 10;
	else
		vars->move.y += 10;
	ft_print_new(vars);
}

void	ft_rotate_map(int k, t_vars *vars)
{
	if (k == W_KEY)
		vars->move.angle_x += 0.01;
	else if (k == Q_KEY)
		vars->move.angle_x -= 0.01;
	else if (k == S_KEY)
		vars->move.angle_y += 0.01;
	else if (k == A_KEY)
		vars->move.angle_y -= 0.01;
	else if (k == X_KEY)
		vars->move.angle_z += 0.01;
	else
		vars->move.angle_z -= 0.01;
	ft_print_new(vars);
}

void	ft_flat_and_proj(int k, t_vars *vars)
{
	if (k == F_KEY)
		vars->move.scale_z += 1;
	else if (k == G_KEY)
		vars->move.scale_z -= 1;
	else if (k == P_KEY)
		vars->move.proj = 0;
	else
		vars->move.proj = 1;
	ft_print_new(vars);
}
