/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constructlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 14:23:15 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 10:42:34 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_constructlst(void *content, size_t content_size,
									t_list *next)
{
	t_list		*new;

	new = NULL;
	new = ft_lstnew(content, content_size);
	new->next = next;
	return (new);
}
