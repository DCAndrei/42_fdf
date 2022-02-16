/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:23:41 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 20:20:11 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_usage_window(t_vars vars)
{
	int		x;

	x = 1000;
	mlx_string_put(vars.mlx, vars.win, x, 20, 0xFFFFFF, "USAGE:");
	mlx_string_put(vars.mlx, vars.win, x, 60, 0xFFFFFF, "Move             \
	< ^ v >");
	mlx_string_put(vars.mlx, vars.win, x, 80, 0xFFFFFF, "Zoom in/out      \
	+/-");
	mlx_string_put(vars.mlx, vars.win, x, 100, 0xFFFFFF, "Flater           \
	f(+) g(-)");
	mlx_string_put(vars.mlx, vars.win, x, 120, 0xFFFFFF, "Rotate x axis    \
	w(+) q(-)");
	mlx_string_put(vars.mlx, vars.win, x, 140, 0xFFFFFF, "Rotate y axis    \
	s(+) a(-)");
	mlx_string_put(vars.mlx, vars.win, x, 160, 0xFFFFFF, "Rotate z axis    \
	x(+) z(-)");
	mlx_string_put(vars.mlx, vars.win, x, 180, 0xFFFFFF, "Parallel proj.   \
	p");
	mlx_string_put(vars.mlx, vars.win, x, 200, 0xFFFFFF, "Isometric proj.  \
	i");
	ft_print_detalis(vars);
}

void	ft_print_detalis(t_vars vars)
{
	char	*str;

	mlx_string_put(vars.mlx, vars.win, 1000, 280, 0xFFFFFF, "DISPLAY INFO:");
	if (vars.move.proj == 1)
		mlx_string_put(vars.mlx, vars.win, 1000, 300, 0xFFFFFF, "Type of proj.:\
		 ISOMETRIC");
	else
		mlx_string_put(vars.mlx, vars.win, 1000, 300, 0xFFFFFF, "Type of proj.:\
		 PARALLEL");
	str = ft_itoa(vars.move.scale);
	mlx_string_put(vars.mlx, vars.win, 1000, 320, 0xFFFFFF, "Width scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 320, 0xFFFFFF, str);
	mlx_string_put(vars.mlx, vars.win, 1000, 340, 0xFFFFFF, "Length scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 340, 0xFFFFFF, str);
	free (str);
	str = ft_itoa(vars.move.scale_z);
	mlx_string_put(vars.mlx, vars.win, 1000, 360, 0xFFFFFF, "Height scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 360, 0xFFFFFF, str);
	free (str);
	str = ft_itoa(vars.move.x);
	mlx_string_put(vars.mlx, vars.win, 1000, 380, 0xFFFFFF, "Move on x:");
	mlx_string_put(vars.mlx, vars.win, 1200, 380, 0xFFFFFF, str);
	free (str);
	ft_print_details_2(vars);
}

void	ft_print_details_2(t_vars vars)
{
	char	*str;
	int		angle;

	str = ft_itoa(vars.move.y);
	mlx_string_put(vars.mlx, vars.win, 1000, 400, 0xFFFFFF, "Move on y:    ");
	mlx_string_put(vars.mlx, vars.win, 1200, 400, 0xFFFFFF, str);
	free (str);
	angle = (int)(vars.move.angle_x * 100);
	str = ft_itoa(angle);
	mlx_string_put(vars.mlx, vars.win, 1000, 420, 0xFFFFFF, "X Angle Rot:    ");
	mlx_string_put(vars.mlx, vars.win, 1200, 420, 0xFFFFFF, str);
	free (str);
	angle = (int)(vars.move.angle_y * 100);
	str = ft_itoa(angle);
	mlx_string_put(vars.mlx, vars.win, 1000, 440, 0xFFFFFF, "Y Angle Rot:    ");
	mlx_string_put(vars.mlx, vars.win, 1200, 440, 0xFFFFFF, str);
	free (str);
	angle = (int)(vars.move.angle_z * 100);
	str = ft_itoa(angle);
	mlx_string_put(vars.mlx, vars.win, 1000, 460, 0xFFFFFF, "Z Angle Rot:    ");
	mlx_string_put(vars.mlx, vars.win, 1200, 460, 0xFFFFFF, str);
	free (str);
}
