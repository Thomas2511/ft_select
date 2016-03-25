/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 19:14:44 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 11:11:10 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t		src_size;

	src_size = ft_strlen(src);
	if (src_size > size)
		ft_strncpy(dst, src, size - 1);
	else
		ft_strcpy(dst, src);
	return (src_size);
}
