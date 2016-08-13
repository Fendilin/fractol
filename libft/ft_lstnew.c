/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:37:29 by vterzian          #+#    #+#             */
/*   Updated: 2015/02/13 13:04:09 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		content = NULL;
		content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	return (list);
}
