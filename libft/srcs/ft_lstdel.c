/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:34:55 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 10:51:19 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*save_next;

	save_next = NULL;
	if (alst)
	{
		while (*alst)
		{
			save_next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = save_next;
		}
	}
}
