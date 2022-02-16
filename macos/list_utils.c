/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:24:36 by acretu            #+#    #+#             */
/*   Updated: 2022/02/14 17:00:34 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_create_list(t_line **list, char *path)
{
	int		fd;
	t_line	*line;
	t_line	*start;

	fd = open(path, O_RDONLY);
	ft_line_error(fd, &line);
	start = *list;
	while (line != NULL)
	{
		if (*list == NULL)
		{
			*list = line;
			start = *list;
		}
		else
		{
			(*list)->next = line;
			(*list) = (*list)->next;
		}
		line = ft_read_line(fd);
	}
	close (fd);
	*list = start;
}

void	ft_line_error(int fd, t_line **line)
{
	if (fd == -1)
	{
		write(1, "Error: File does not exist or have no permission\n", 49);
		exit(EXIT_FAILURE);
	}
	*line = ft_read_line(fd);
	if (*line == NULL)
	{
		close (fd);
		free (*line);
		exit (EXIT_FAILURE);
	}
}

void	ft_print_list(t_line *list)
{
	int		len;

	while (list->next != NULL)
	{
		len = 0;
		while (list->str[len] != '\0')
			len++;
		write(1, list->str, len);
		write(1, "\n", 2);
		list = list->next;
	}
}

void	ft_free_list(t_line **list)
{
	t_line	*tmp;

	while (*list != NULL)
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free (tmp->str);
		tmp->str = NULL;
		tmp->next = NULL;
		free (tmp);
	}
}

int	ft_list_size(t_line *list)
{
	int		size;

	if (list == NULL)
		return (0);
	size = 0;
	while (list->next != NULL)
	{
		size += 1;
		list = list->next;
	}
	return (size + 1);
}
