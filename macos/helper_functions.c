/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:16:29 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 11:33:16 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_init_isometric(t_vars *vars)
{
	int		i;
	int		j;

	vars->proj = (t_map **)malloc(sizeof(t_map) * vars->array.l);
	if (vars->proj == NULL)
	{
		ft_free_grid(vars->array.map, vars->array.l);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i++ < vars->array.l)
	{
		vars->proj[i - 1] = (t_map *)malloc(sizeof(t_map) * vars->array.w);
		if (vars->proj[i - 1] == NULL)
		{
			ft_free_grid(vars->array.map, vars->array.l);
			j = 0;
			while (j++ < i)
				free (vars->proj[j - 1]);
			free (vars->proj);
			exit (EXIT_FAILURE);
		}
	}
	ft_fill_isometric(vars);
}

void	ft_fill_isometric(t_vars *vars)
{
	int		i;
	int		j;

	vars->move.x = 0;
	vars->move.y = 0;
	vars->move.scale = 1;
	vars->move.scale_z = 1;
	vars->move.proj = 1;
	i = 0;
	while (i < vars->array.l)
	{
		j = 0;
		while (j < vars->array.w)
		{
			vars->proj[i][j].x = (vars->array.map[i][j].x - \
			vars->array.map[i][j].y) * cos(0.5523599);
			vars->proj[i][j].y = (-vars->array.map[i][j].z + (vars->array.\
			map[i][j].x + vars->array.map[i][j].y) * sin(0.523599));
			vars->proj[i][j].color = vars->array.map[i][j].color;
			j += 1;
		}
		i += 1;
	}
}

void	ft_free_isometric(t_vars *vars)
{
	int		i;

	i = vars->array.l;
	while (i-- > 0)
	{
		free (vars->proj[i]);
	}
	free (vars->proj);
}

void	ft_isometric(t_vars *vars)
{
	int		i;
	int		j;
	t_point	temp;

	i = 0;
	while (i < vars->array.l)
	{
		j = 0;
		while (j < vars->array.w)
		{
			temp = ft_scale(vars->array.map[i][j], *vars);
			vars->proj[i][j].x = (temp.x - temp.y) * cos(0.523599);
			vars->proj[i][j].y = -temp.z + (temp.x + temp.y) * sin(0.523599);
			vars->proj[i][j].color = temp.color;
			j += 1;
		}
		i += 1;
	}
}

void	ft_paralel(t_vars *vars)
{
	int		i;
	int		j;
	t_point	tmp;
	double	angle;

	angle = 30 * 3.14 / 180;
	i = 0;
	while (i < vars->array.l)
	{
		j = 0;
		while (j < vars->array.w)
		{
			tmp = ft_scale(vars->array.map[i][j], *vars);
			vars->proj[i][j].x = tmp.x + tmp.z * cos(angle);
			vars->proj[i][j].y = tmp.y + tmp.z * sin(angle);
			vars->proj[i][j].color = tmp.color;
			j += 1;
		}
		i += 1;
	}
}
