/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:43:48 by acretu            #+#    #+#             */
/*   Updated: 2022/02/12 23:59:13 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_rotate_z(t_vars vars, t_point *point)
{
	t_point		tmp;
	double		angle;

	angle = vars.move.angle_z;
	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	tmp.color = point->color;
	point->x = tmp.x * cos(angle) - tmp.y * sin(angle);
	point->y = tmp.x * sin(angle) + tmp.y * cos(angle);
}

void	ft_rotate_x(t_vars vars, t_point *point)
{
	t_point		tmp;
	double		angle;

	angle = vars.move.angle_x;
	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	tmp.color = point->color;
	point->y = tmp.y * cos(angle) + tmp.z * sin(angle);
	point->z = -tmp.y * sin(angle) + tmp.z * cos(angle);
}

void	ft_rotate_y(t_vars vars, t_point *point)
{
	t_point		tmp;
	double		angle;

	angle = vars.move.angle_y;
	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	tmp.color = point->color;
	point->x = tmp.x * cos(angle) + tmp.z * sin(angle);
	point->z = -tmp.x * sin(angle) + tmp.z * cos(angle);
}
