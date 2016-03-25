/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:05:29 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/11 14:57:31 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_select.h"

static int			ft_rightarr(int buffer)
{
	int				i;

	if (buffer == RIGHT_ARROW)
	{
		if (ft_currentidx(singleton()->clst, singleton()->current)
				< ft_clstsize(singleton()->clst) - singleton()->winsz->ws_row)
		{
			i = 0;
			while (i < singleton()->winsz->ws_row)
			{
				singleton()->current = singleton()->current->next;
				i++;
			}
		}
		else
			singleton()->current = singleton()->current->next;
	}
	return (1);
}

static int			ft_leftarr(int buffer)
{
	int				i;

	if (buffer == LEFT_ARROW)
	{
		if (ft_currentidx(singleton()->clst, singleton()->current)
				- singleton()->winsz->ws_row >= 0)
		{
			i = 0;
			while (i < singleton()->winsz->ws_row)
			{
				singleton()->current = singleton()->current->previous;
				i++;
			}
		}
		else
			singleton()->current = singleton()->current->previous;
	}
	return (1);
}

static int			ft_arrows(int buffer)
{
	if (buffer == UP_ARROW)
		singleton()->current = singleton()->current->previous;
	if (buffer == DOWN_ARROW)
		singleton()->current = singleton()->current->next;
	ft_rightarr(buffer);
	ft_leftarr(buffer);
	return (1);
}

int					ft_keycmp(int buffer)
{
	ft_arrows(buffer);
	if (buffer == SPACE)
	{
		singleton()->current->selected ^= 1;
		singleton()->current = singleton()->current->next;
	}
	if (buffer == DELETE || buffer == BACKSPACE)
	{
		if (singleton()->current->first == 1)
			singleton()->clst = singleton()->clst->next;
		ft_clstdelone(&singleton()->current);
		if (!singleton()->current)
			ft_reset();
		ft_getmax(singleton()->clst);
	}
	if (buffer == ESCAPE)
		ft_reset();
	if (buffer == RETURN)
		ft_returnslct();
	return (1);
}
