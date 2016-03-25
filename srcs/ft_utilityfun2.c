/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilityfun2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 16:31:27 by tdieumeg          #+#    #+#             */
/*   Updated: 2016/03/25 18:41:58 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_select.h"

int					ft_getmax(t_clst *clst)
{
	int				i;
	unsigned int	maxlen;

	i = 0;
	maxlen = 0;
	while (clst && (!clst->first || i == 0))
	{
		if (ft_strlen(clst->value) > maxlen)
			maxlen = ft_strlen(clst->value);
		clst = clst->next;
		if (clst->first)
			i = 1;
	}
	singleton()->maxlen = maxlen;
	return (1);
}

int					ft_clstsize(t_clst *clst)
{
	int				i;
	int				j;
	t_clst			*save;

	i = 0;
	j = 0;
	save = clst;
	while (!save->first || i == 0)
	{
		save = save->next;
		j++;
		if (save->first)
			i = 1;
	}
	return (j);
}

int					ft_currentidx(t_clst *clst, t_clst *current)
{
	t_clst			*save;
	int				i;

	save = clst;
	i = 0;
	while (save != current)
	{
		save = save->next;
		i++;
	}
	return (i);
}
