/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:40:25 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/01 21:05:36 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int				ft_word_count(char *str, char c)
{
	int			words;
	char		*next;

	words = 0;
	while (str && *str)
	{
		while (*str == c)
			str++;
		next = ft_strchr(str, c);
		if (*str)
			words++;
		str = next;
	}
	return (words);
}

char			**ft_strsplit(const char *str, char c)
{
	char		**split;
	char		*ptr;
	char		*next;
	int			i;

	ptr = (char *)str;
	split = (char **)malloc(sizeof(char *) * (ft_word_count(ptr, c) + 1));
	i = 0;
	while (ptr && *ptr && ft_word_count(ptr, c))
	{
		while (*ptr == c)
			ptr++;
		next = ft_strchr(ptr, c);
		if (next)
			split[i] = ft_strsub(str, ptr - str, next - ptr);
		else
			split[i] = ft_strsub(str, ptr - str, ft_strlen(str) - (ptr - str));
		ptr = next;
		i++;
	}
	split[i] = NULL;
	return (split);
}
