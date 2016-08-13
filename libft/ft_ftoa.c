/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 13:20:20 by vterzian          #+#    #+#             */
/*   Updated: 2015/06/11 13:21:28 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_convert(float n, size_t preci, char *buff)
{
	if (n < 0)
	{
		n = -n;
		buff[0] = '-';
		buff[1] = '\0';
	}
	else
		buff[0] = '\0';
	ft_strcat(buff, ft_itoa(n));
	n -= (int)n;
	if (preci > 0)
		ft_strcat(buff, ".");
	while (preci > 0)
	{
		n *= 10;
		ft_strcat(buff, ft_itoa(n));
		n -= (int)n;
		preci--;
	}
}

static size_t	ft_float_len(float n, size_t preci)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	if (preci > 0)
		len++;
	len += preci;
	return (len);
}

char			*ft_ftoa(float n, size_t preci)
{
	char	*buff;

	if ((buff = malloc(sizeof(char) * ft_float_len(n, preci) + 1)))
		ft_convert(n, preci, buff);
	return (buff);
}
