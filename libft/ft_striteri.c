/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:06:18 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/24 15:57:31 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int len;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	len = strlen(s);
	while (i < len)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
