/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:01:21 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/19 20:10:43 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*strnew;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen((char*)s);
	strnew = ft_strnew(size);
	if (strnew == NULL)
		return (NULL);
	while (i < size)
	{
		strnew[i] = f(s[i]);
		i++;
	}
	return (strnew);
}
