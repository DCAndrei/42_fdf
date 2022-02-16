/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:58:27 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 15:33:30 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_draw_line_low(t_vars *vars, t_map p1, t_map p2)
{
	t_new_line	point;

	point.pp.x = p1.x;
	point.pp.y = p1.y;
	point.pp.color = p1.color;
	point.dx = p2.x - p1.x;
	point.dy = p2.y - p1.y;
	point.n = 1;
	if (point.dy < 0)
	{
		point.dy *= -1;
		point.n = -1;
	}
	point.p = 2 * point.dy - point.dx;
	ft_draw_low(&point, p1, p2, vars);
}

void	ft_draw_low(t_new_line *point, t_map p1, t_map p2, t_vars *vars)
{
	while (point->pp.x <= p2.x)
	{
		my_mlx_pixel_put(&vars->img, point->pp.x, point->pp.y, \
		ft_get_color(p1, p2, point->pp));
		point->pp.x += 1;
		if (point->p < 0)
			point->p = point->p + 2 * point->dy;
		else
		{
			point->p = point->p + 2 * point->dy - 2 * point->dx;
			point->pp.y += point->n;
		}
	}
}

void	ft_draw_line_high(t_vars *vars, t_map p1, t_map p2)
{
	t_new_line	point;

	point.pp.x = p1.x;
	point.pp.y = p1.y;
	point.pp.color = p1.color;
	point.dx = p2.x - p1.x;
	point.dy = p2.y - p1.y;
	point.n = 1;
	if (point.dx < 0)
	{
		point.dx *= -1;
		point.n = -1;
	}
	point.p = 2 * point.dx - point.dy;
	ft_draw_high(&point, p1, p2, vars);
}

void	ft_draw_high(t_new_line *point, t_map p1, t_map p2, t_vars *vars)
{
	while (point->pp.y <= p2.y)
	{
		my_mlx_pixel_put(&vars->img, point->pp.x, point->pp.y, \
		ft_get_color(p1, p2, point->pp));
		point->pp.y += 1;
		if (point->p < 0)
			point->p = point->p + 2 * point->dx;
		else
		{
			point->p = point->p - 2 * point->dy + 2 * point->dx;
			point->pp.x += point->n;
		}
	}
}

void	ft_draw_line(t_vars *vars, t_map p1, t_map p2)
{
	t_point	pp;
	int		dx;
	int		dy;

	pp.x = p1.x;
	pp.y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (abs(dy) < abs(dx))
	{
		if (p1.x > p2.x)
			ft_draw_line_low(vars, p2, p1);
		else
			ft_draw_line_low(vars, p1, p2);
	}
	else
	{
		if (p1.y > p2.y)
			ft_draw_line_high(vars, p2, p1);
		else
			ft_draw_line_high(vars, p1, p2);
	}
}
