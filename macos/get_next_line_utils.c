/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:03 by acretu            #+#    #+#             */
/*   Updated: 2022/02/01 20:37:31 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*ret;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	ret = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i++ < s1_len)
		ret[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < s2_len)
		ret[s1_len + i - 1] = s2[i - 1];
	ret[s1_len + i - 1] = '\0';
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ret;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *s)
{
	char		*str;
	size_t		len;
	size_t		i;

	str = NULL;
	len = 0;
	while (s[len] != '\0')
		len++;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

void	ft_free(char **val)
{
	char		*tmp;

	tmp = *val;
	free (tmp);
	*val = NULL;
}
