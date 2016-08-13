/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:10:16 by vterzian          #+#    #+#             */
/*   Updated: 2014/11/24 15:56:44 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;
	int len;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	len = strlen(s);
	while (i < len)
	{
		(*f)(s);
		s++;
		i++;
	}
}
