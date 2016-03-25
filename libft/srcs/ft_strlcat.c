/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 17:08:21 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 11:10:37 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_size;
	size_t		src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size < dst_size)
		return (src_size + size);
	while (*dst != '\0' && size--)
		dst++;
	while (size-- > 1 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst_size + src_size);
}
