/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:02:14 by acretu            #+#    #+#             */
/*   Updated: 2022/02/01 20:36:13 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

char	*ft_init(char **val, int fd);
char	*ft_check_return(char **src, ssize_t n_bytes, char **buf);
char	*ft_strchr_return(char **val);
void	ft_iterate(char **val, int fd, ssize_t *n, char **buf);

char	*get_next_line(int fd)
{
	static char		*val[MAX_FD];
	char			*buf;
	ssize_t			n_bytes;
	char			*str;

	if (ft_init(&val[fd], fd) == NULL)
		return (NULL);
	if (ft_strchr(val[fd], '\n'))
		return (ft_strchr_return(&val[fd]));
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	n_bytes = read(fd, buf, BUFFER_SIZE);
	buf[n_bytes] = '\0';
	if (n_bytes == 0)
	{
		str = ft_strdup(val[fd]);
		free (buf);
		ft_free(&val[fd]);
		return (str);
	}
	while (n_bytes && !ft_strchr(buf, '\n'))
		ft_iterate(&val[fd], fd, &n_bytes, &buf);
	return (ft_check_return(&val[fd], n_bytes, &buf));
}

char	*ft_init(char **val, int fd)
{
	char		*init;
	char		*tmp;
	ssize_t		n_bytes;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	if (*val == NULL)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (tmp == NULL)
			return (NULL);
		n_bytes = read(fd, tmp, BUFFER_SIZE);
		if (n_bytes < 1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[n_bytes] = '\0';
		init = ft_strdup(tmp);
		*val = init;
		free (tmp);
	}
	return (*val);
}

char	*ft_check_return(char **src, ssize_t n_bytes, char **buf)
{
	char		*tmp;
	char		*str;

	tmp = NULL;
	str = NULL;
	tmp = ft_strjoin(*src, *buf);
	ft_free(&*src);
	if (n_bytes == 0 && !ft_strchr(*buf, '\n'))
	{
		free (*buf);
		return (tmp);
	}
	else
	{
		free (*buf);
		if (tmp[ft_strchr(tmp, '\n') - tmp + 1] == '\0')
		{
			*src = NULL;
			return (tmp);
		}
		str = ft_substr(tmp, 0, ft_strchr(tmp, '\n') - tmp + 1);
		*src = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free (tmp);
		return (str);
	}
}

char	*ft_strchr_return(char **val)
{
	char		*str;
	char		*buf;

	str = ft_substr(*val, 0, ((ft_strchr(*val, '\n') - *val + 1)));
	buf = ft_strdup(ft_strchr(*val, '\n') + 1);
	ft_free(&*val);
	if (*buf == '\0')
		free (buf);
	else
		*val = buf;
	return (str);
}

void	ft_iterate(char **val, int fd, ssize_t *n, char **buf)
{
	char		*str;
	char		*tmp;
	ssize_t		i;

	str = ft_strjoin(*val, *buf);
	ft_free(&*val);
	*val = str;
	i = 0;
	tmp = *buf;
	while (i < BUFFER_SIZE + 1)
	{
		tmp[i] = '\0';
		i++;
	}
	*buf = tmp;
	*n = read(fd, *buf, BUFFER_SIZE);
}
