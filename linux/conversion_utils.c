/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:58:18 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 20:08:59 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_point	**ft_create_array(t_line **lst, int *width, int *lenght)
{
	t_point	**array;
	int		i;
	t_line	*start;

	start = *lst;
	*lenght = ft_list_size(*lst);
	*width = ft_get_lenght((*lst)->str, ' ');
	array = (t_point **)malloc(sizeof(t_point *) * (*lenght));
	if (array == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < *lenght)
	{
		array[i] = ft_create_line((*lst)->str, *width, i);
		*lst = (*lst)->next;
		i += 1;
	}
	*lst = start;
	return (array);
}

int	ft_get_lenght(char *str, char c)
{
	int		size;

	size = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == c && *str != '\0' && *str != '\n')
			str++;
		if (*str != '\0' && *str != '\n')
			size += 1;
		while (*str != c && *str != '\0' && *str != '\n')
			str++;
	}
	return (size);
}

t_point	*ft_create_line(char *str, int width, int y)
{
	t_point	*ret;
	int		i;

	ret = (t_point *)malloc(sizeof(t_point) * width);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < width)
	{
		ret[i].x = i;
		ret[i].y = y;
		ret[i].z = ft_get_z(&str, &ret[i].color);
		i += 1;
	}
	return (ret);
}

void	ft_free_grid(t_point **array, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		free (array[i]);
		i += 1;
	}
	free (array);
}
