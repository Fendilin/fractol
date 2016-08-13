/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:10:37 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/10 18:00:40 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_strlen(s2);
	if (size == 0)
	{
		return ((char*)s1);
	}
	while (s1[i] != '\0')
	{
		while (s2[j] == s1[i + j])
		{
			if (j == size - 1)
				return ((char*)(s1 + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
