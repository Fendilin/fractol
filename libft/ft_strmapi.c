/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:02:35 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/19 19:43:58 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*strnew;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen((char*)s);
	strnew = ft_strnew(size);
	if (strnew == NULL)
		return (NULL);
	while (i < size)
	{
		strnew[i] = f(i, s[i]);
		i++;
	}
	return (strnew);
}
