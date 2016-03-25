/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:32:52 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/11 15:11:38 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

t_clst			*ft_clstnew(char *value, t_clst *prev, t_clst *next, int first)
{
	t_clst		*new;

	if ((new = (t_clst*)malloc(sizeof(t_clst))) != NULL)
	{
		new->value = value;
		new->previous = prev;
		new->next = next;
		new->first = first;
		new->selected = FALSE;
	}
	else
		ft_putendl_fd("ft_clstnew: malloc fail", 2);
	return (new);
}
