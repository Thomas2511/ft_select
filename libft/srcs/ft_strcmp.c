/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 12:27:14 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/01 20:09:21 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char		*s_one;
	const unsigned char		*s_two;

	s_one = (const unsigned char*)s1;
	s_two = (const unsigned char*)s2;
	while (*s_one == *s_two && *s_one != '\0')
	{
		s_one++;
		s_two++;
	}
	return (*s_one - *s_two);
}
