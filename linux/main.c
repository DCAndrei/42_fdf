/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:27:00 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 13:53:48 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	ft_print_error(void);

int	main(int argc, char *argv[])
{
	t_line		*list;
	t_vars		vars;

	if (argc != 2)
	{
		ft_print_error();
		exit(EXIT_FAILURE);
	}
	list = NULL;
	ft_create_list(&list, argv[1]);
	vars.array.map = ft_create_array(&list, &vars.array.w, &vars.array.l);
	ft_free_list(&list);
	vars.nb_img = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Fdf Project");
	ft_init_isometric(&vars);
	ft_find_margins(&vars);
	ft_print_new(&vars);
	mlx_key_hook(vars.win, ft_print_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

static void	ft_print_error(void)
{
	if (write(1, "Error: Bad argument, expected ./fdf <file>\n", 43) == -1)
		exit(EXIT_FAILURE);
}
