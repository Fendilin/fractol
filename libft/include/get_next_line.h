/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:59:37 by vterzian          #+#    #+#             */
/*   Updated: 2014/12/01 12:32:02 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 312
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(int const fd, char **line);
#endif
