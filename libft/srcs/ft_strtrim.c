/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:27:59 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/01 20:01:44 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char				*ft_strtrim(const char *s)
{
	char			*begin;
	char			*end;

	if (!s)
		return (NULL);
	begin = (char *)s;
	end = (char *)s;
	while (*begin == ' ' || *begin == '\n' || *begin == '\t')
	{
		begin++;
		end++;
	}
	while (*end != '\0')
		end++;
	while ((*end == ' ' || *end == '\n' || *end == '\t' || *end == '\0')
			&& end > begin)
		end--;
	return (ft_strsub(s, begin - s, end - begin + 1));
}
