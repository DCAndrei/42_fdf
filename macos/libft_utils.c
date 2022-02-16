/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:38:40 by acretu            #+#    #+#             */
/*   Updated: 2022/02/13 14:39:12 by acretu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;

	len = len_nb(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	len--;
	return (put_nb(ret, n, len));
}

int	len_nb(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = n / 10;
		n = n * (-1);
		len = len + 2;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*put_nb(char *str, int n, int len)
{
	int		stop;

	stop = 0;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		if ((n % 10) < 0)
			str[len] = '0' - (n % 10);
		else
			str[len] = '0' + (n % 10);
		n = n / 10;
		n = -n;
		stop++;
		len --;
	}
	while (len >= stop && n)
	{
		str[len] = '0' + (n % 10);
		len--;
		n = n / 10;
	}
	return (str);
}
