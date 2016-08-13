/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:44 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/10 18:03:08 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int size;

	i = 0;
	j = 0;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		while (s2[j] == s1[i + j] && (i + j) < n)
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
