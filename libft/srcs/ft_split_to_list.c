/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:35:27 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/01 21:14:45 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_split_to_list(char const *s, char *special)
{
	t_list			*list;
	char			*buff;
	int				i;

	list = NULL;
	buff = ft_strnew(ft_strlen(s));
	i = 0;
	while (s && *s)
	{
		if (ft_strchr(special, *s))
		{
			if (buff[0])
				ft_lstpushback(&list, buff, ft_strlen(buff) + 1);
			ft_bzero(buff, i);
			i = 0;
		}
		else
			buff[i++] = *s;
		s++;
	}
	if (buff[0])
		ft_lstpushback(&list, buff, ft_strlen(buff) + 1);
	free(buff);
	return (list);
}
