/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:34:24 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/26 19:06:30 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(unsigned int n)
{
	int i;
	int nbr;

	nbr = n;
	i = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*strnew;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intlen(n);
	if (n < 0)
		size += 1;
	strnew = ft_strnew(size);
	if (strnew == NULL)
		return (NULL);
	if (n < 0)
	{
		strnew[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		strnew[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (strnew);
}
