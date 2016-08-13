/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:04:51 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/19 16:39:28 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strnew;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	strnew = ft_strnew(len);
	if (strnew == NULL)
		return (NULL);
	i = 0;
	while (i < len + start)
	{
		if (i >= start)
			strnew[i - start] = s[i];
		i++;
	}
	return (strnew);
}
