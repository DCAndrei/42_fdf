/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:23:41 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 20:19:42 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_usage_window(t_vars v)
{
	int		x;
	int		c;

	x = 1000;
	c = 0xFFFFFF;
	mlx_string_put(v.mlx, v.win, x, 20, c, "USAGE:");
	mlx_string_put(v.mlx, v.win, x, 60, c, "Move             < ^ v >");
	mlx_string_put(v.mlx, v.win, x, 80, c, "Zoom in/out      +/-");
	mlx_string_put(v.mlx, v.win, x, 100, c, "Flater           f(+) g(-)");
	mlx_string_put(v.mlx, v.win, x, 120, c, "Rotate x axis    w(+) q(-)");
	mlx_string_put(v.mlx, v.win, x, 140, c, "Rotate y axis    s(+) a(-)");
	mlx_string_put(v.mlx, v.win, x, 160, c, "Rotate z axis    x(+) z(-)");
	mlx_string_put(v.mlx, v.win, x, 180, c, "Parallel proj.   p");
	mlx_string_put(v.mlx, v.win, x, 200, c, "Isometric proj.  i");
	ft_print_detalis(v);
}

void	ft_print_detalis(t_vars vars)
{
	char	*str;
	int		c;

	c = 0xFFFFFF;
	mlx_string_put(vars.mlx, vars.win, 1000, 280, c, "DISPLAY INFO:");
	if (vars.move.proj == 1)
		mlx_string_put(vars.mlx, vars.win, 1000, 300, c, "Type:  ISOMETRIC");
	else
		mlx_string_put(vars.mlx, vars.win, 1000, 300, c, "Type:  PARALLEL");
	str = ft_itoa(vars.move.scale);
	mlx_string_put(vars.mlx, vars.win, 1000, 320, c, "Width scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 320, c, str);
	mlx_string_put(vars.mlx, vars.win, 1000, 340, c, "Length scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 340, c, str);
	free (str);
	str = ft_itoa(vars.move.scale_z);
	mlx_string_put(vars.mlx, vars.win, 1000, 360, c, "Height scale:");
	mlx_string_put(vars.mlx, vars.win, 1200, 360, c, str);
	free (str);
	str = ft_itoa(vars.move.x);
	mlx_string_put(vars.mlx, vars.win, 1000, 380, c, "Move on x:");
	mlx_string_put(vars.mlx, vars.win, 1200, 380, c, str);
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
