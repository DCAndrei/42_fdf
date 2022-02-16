/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:21:23 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 16:36:31 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_print_map(int k, t_vars *vars)
{
	if (k == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_isometric(vars);
		ft_free_grid(vars->array.map, vars->array.l);
		exit (0);
	}
	else if (k == PL_KEY || k == MN_KEY)
		ft_scale_map(k, vars);
	else if (k == RIGHT_KEY || k == LEFT_KEY || k == UP_KEY || k == DOWN_KEY)
		ft_move_map(k, vars);
	else if (k == W_KEY)
	{
		vars->move.angle_x += 0.01;
		ft_print_new(vars);
	}
	else if (k == Q_KEY || k == W_KEY || k == A_KEY || k == S_KEY || \
	k == Z_KEY || k == X_KEY)
		ft_rotate_map(k, vars);
	else if (k == F_KEY || k == G_KEY || k == P_KEY || k == I_KEY)
		ft_flat_and_proj(k, vars);
	else
		mlx_string_put(vars->mlx, vars->win, 1000, 260, 0xFFFFFF, \
		"Wrong key,read USAGE");
	return (0);
}

void	ft_print_new(t_vars *vars)
{
	if (vars->nb_img == 0)
		vars->nb_img = 1;
	else
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, 1280, 720);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (vars->move.proj == 1)
		ft_isometric(vars);
	else
		ft_paralel(vars);
	ft_find_offset(vars);
	ft_print_vertical(vars);
	ft_print_horizontal(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_usage_window(*vars);
}

int	ft_check_point(t_map p1, t_map *new_p)
{
	int		t;

	new_p->color = p1.color;
	new_p->x = p1.x;
	new_p->y = p1.y;
	t = 0;
	if (p1.x > W_WIDTH || p1.x < 0 || p1.y > W_LENGTH || p1.y < 0)
	{
		t = 1;
		if (p1.x > W_WIDTH)
			new_p->x = W_WIDTH;
		else if (p1.x < 0)
			new_p->x = 0;
		if (p1.y > W_LENGTH)
			new_p->y = W_LENGTH;
		else if (p1.y < 0)
			new_p->y = 0;
	}
	return (t);
}

void	ft_print_horizontal(t_vars *vars)
{
	int		i;
	int		j;
	t_map	p;
	t_map	p0;

	i = 0;
	while (i < vars->array.l)
	{
		j = 0;
		while (j < vars->array.w - 1)
		{
			if (ft_check_point(vars->proj[i][j + 1], &p) && \
			!ft_check_point(vars->proj[i][j], &p0))
				ft_draw_line(vars, vars->proj[i][j], p);
			else if (!ft_check_point(vars->proj[i][j], &p0))
				ft_draw_line(vars, vars->proj[i][j], vars->proj[i][j + 1]);
			j += 1;
		}
		i += 1;
	}
}

void	ft_print_vertical(t_vars *vars)
{
	int		i;
	int		j;
	t_map	p;
	t_map	p0;

	i = 0;
	while (i < vars->array.w)
	{
		j = 0;
		while (j < vars->array.l - 1)
		{
			if (ft_check_point(vars->proj[j + 1][i], &p) && \
			!ft_check_point(vars->proj[j][i], &p0))
				ft_draw_line(vars, vars->proj[j][i], p);
			else if (!ft_check_point(vars->proj[j][i], &p0))
				ft_draw_line(vars, vars->proj[j][i], vars->proj[j + 1][i]);
			j += 1;
		}
		i += 1;
	}
}
