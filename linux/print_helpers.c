/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:14:52 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 15:32:37 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_point	ft_scale(t_point point, t_vars vars)
{
	t_point		ret;

	ret.x = point.x * vars.move.scale;
	ret.y = point.y * vars.move.scale;
	ret.z = point.z * vars.move.scale_z;
	ret.color = point.color;
	ft_rotate_x(vars, &ret);
	ft_rotate_y(vars, &ret);
	ft_rotate_z(vars, &ret);
	return (ret);
}

void	ft_find_offset(t_vars *vars)
{
	int		i;
	int		j;

	vars->offset_x = vars->proj[0][0].x;
	vars->offset_y = vars->proj[0][0].y;
	i = 0;
	while (i++ < vars->array.l)
	{
		j = 0;
		while (j++ < vars->array.w)
		{
			if (vars->offset_x > vars->proj[i - 1][j - 1].x)
				vars->offset_x = vars->proj[i - 1][j - 1].x;
			if (vars->offset_y > vars->proj[i - 1][j - 1].y)
				vars->offset_y = vars->proj[i - 1][j - 1].y;
		}
	}
	ft_modify_offset(vars);
}

void	ft_modify_offset(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < vars->array.l)
	{
		j = 0;
		while (j++ < vars->array.w)
		{
			vars->proj[i - 1][j - 1].x += -vars->offset_x + 50 + vars->move.x;
			vars->proj[i - 1][j - 1].y += -vars->offset_y + 50 + vars->move.y;
		}
	}
}

void	ft_find_margins(t_vars *vars)
{
	int		i;
	int		j;
	int		max[2];
	int		scale[2];

	i = 0;
	max[0] = vars->proj[0][0].x;
	max[1] = vars->proj[0][0].y;
	while (i++ < vars->array.l)
	{
		j = 0;
		while (j++ < vars->array.w)
		{
			if (max[0] < vars->proj[i - 1][j - 1].x)
				max[0] = vars->proj[i - 1][j - 1].x;
			if (max[1] < vars->proj[i - 1][j - 1].y)
				max[1] = vars->proj[i - 1][j - 1].y;
		}
	}
	scale[0] = (W_WIDTH - 200) / max[0];
	scale[1] = (W_LENGTH - 200) / max[1];
	if (scale[0] < scale[1])
		vars->move.scale = scale[0];
	else
		vars->move.scale = scale[1];
}
