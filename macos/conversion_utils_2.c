/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:29:27 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 19:57:01 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_get_z(char **str, int *color)
{
	char	*sub;
	int		ret;

	sub = NULL;
	while (*(*str) == ' ' && *(*str) != '\0')
		(*str)++;
	if (ft_strchr(*str, ' ') == NULL)
		ft_get_z_helper(str, &ret, color);
	else
	{
		ft_get_z_helper_2(str, &ret, color, &sub);
		free (sub);
	}
	return (ret);
}

void	ft_get_z_helper(char **str, int *ret, int *color)
{
	char	*sub;

	if (ft_strchr(*str, ',') == NULL)
	{
		sub = ft_substr(*str, 0, (ft_strchr(*str, '\0') - *str));
		*str = ft_strchr(*str, '\0');
		*ret = ft_atoi(sub);
		*color = WHITE;
		free (sub);
	}
	else
	{
		sub = ft_substr(*str, 0, (ft_strchr(*str, ',') - *str));
		*str = ft_strchr(*str, ',') + 1;
		*ret = ft_atoi(sub);
		free (sub);
		sub = ft_substr(*str, 0, (ft_strchr(*str, '\0') - *str));
		*color = ft_hex_color(sub);
		*str = ft_strchr(*str, '\0');
		free (sub);
	}
}

void	ft_get_z_helper_2(char **str, int *ret, int *color, char **sub)
{
	if (ft_strchr(*str, ' ') < ft_strchr(*str, ',') && \
	ft_strchr(*str, ',') != NULL)
	{
		*sub = ft_substr(*str, 0, (ft_strchr(*str, ' ') - *str));
		*str = ft_strchr(*str, ' ') + 1;
		*ret = ft_atoi(*sub);
		*color = WHITE;
	}
	else if (ft_strchr(*str, ',') != NULL)
	{
		*sub = ft_substr(*str, 0, (ft_strchr(*str, ',') - *str));
		*str = ft_strchr(*str, ',') + 1;
		*ret = ft_atoi(*sub);
		free (*sub);
		*sub = ft_substr(*str, 0, (ft_strchr(*str, ' ') - *str));
		*color = ft_hex_color(*sub);
		*str = ft_strchr(*str, ' ') + 1;
	}
	else
	{
		*sub = ft_substr(*str, 0, (ft_strchr(*str, ' ') - *str));
		*str = ft_strchr(*str, ' ') + 1;
		*ret = ft_atoi(*sub);
		*color = WHITE;
	}
}
