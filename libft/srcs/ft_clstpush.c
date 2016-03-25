/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:13:22 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/09 20:33:34 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"libft.h"

t_clst			*ft_clstpush(char *value, t_clst **clst, int first)
{
	t_clst		*new;

	if (*clst)
	{
		new = ft_clstnew(value, (*clst)->previous, (*clst), first);
		(*clst)->previous->next = new;
		(*clst)->previous = new;
		if (first)
		{
			(*clst)->first = FALSE;
			clst = &new;
			return (new);
		}
		else
			return (*clst);
	}
	else
	{
		new = ft_clstnew(value, NULL, NULL, TRUE);
		new->previous = new;
		new->next = new;
		clst = &new;
		return (new);
	}
}
