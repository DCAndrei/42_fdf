/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:18:55 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 19:53:30 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		nb;

	nb = 0;
	while ((*str >= 9 && *str <= 14) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * nb));
}

char	*ft_strchr(char *str, char c)
{
	while (*str != '\0' && *str != c)
		str += 1;
	if (*str == '\0' && c != '\0')
		return (NULL);
	else
		return (str);
}

int	ft_hex_color(char *str)
{
	int		ret;
	int		i;

	str += 2;
	i = 0;
	ret = 0;
	while (*str != ' ' && *str != '\n' && *str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			ret = ret * 16 + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			ret = ret * 16 + (10 + *str - 'a');
		else if (*str >= 'A' && *str <= 'F')
			ret = ret * 16 + (10 + *str - 'A');
		else
		{
			write(1, "Input file error, color error.\n", 31);
			exit (EXIT_FAILURE);
		}
		str++;
	}
	return (ret);
}

t_line	*ft_read_line(int fd)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line) * 1);
	if (line == NULL)
		exit(EXIT_FAILURE);
	line->str = get_next_line(fd);
	line->next = NULL;
	if (line->str != NULL)
		return (line);
	else
	{
		free (line);
		return (NULL);
	}
}
