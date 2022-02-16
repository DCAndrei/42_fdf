/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:26:58 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 12:29:09 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

double	ft_percent(int start, int end, int current)
{
	double		place;
	double		dist;

	place = current - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	else
		return (place / dist);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	ft_get_color(t_map p1, t_map p2, t_point current)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == p2.color)
		return (current.color);
	if (p2.x - p1.x > p2.y - p1.y)
		percentage = ft_percent(p1.x, p2.x, current.x);
	else
		percentage = ft_percent(p1.y, p2.y, current.y);
	red = get_light((p1.color >> 16) & 0xFF, (p2.color >> 16) \
	& 0xFF, percentage);
	green = get_light((p1.color >> 8) & 0xFF, (p2.color >> 8) \
	& 0xFF, percentage);
	blue = get_light(p1.color & 0xFF, p2.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
