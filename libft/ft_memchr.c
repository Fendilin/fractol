/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:35:53 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/05 21:25:36 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	if (s == NULL)
		return (NULL);
	str = s;
	while (n--)
	{
		if (*str != (unsigned char)c)
			str++;
		else
			return ((void*)str);
	}
	return (NULL);
}
