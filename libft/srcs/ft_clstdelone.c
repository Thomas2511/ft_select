/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 12:28:55 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/11 15:16:03 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include				"libft.h"

void					ft_clstdelone(t_clst **clst)
{
	t_clst				*save;

	save = NULL;
	if (*clst)
	{
		save = *clst;
		(*clst)->previous->next = (*clst)->next;
		(*clst)->next->previous = (*clst)->previous;
		if ((*clst)->first == TRUE && (*clst)->next)
			(*clst)->next->first = TRUE;
		if ((*clst)->next == *clst)
			*clst = NULL;
		else
			*clst = (*clst)->next;
		free(save);
	}
}
