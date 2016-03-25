/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:47:41 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/11 15:05:21 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_select.h"

int					ft_putcharslct(int c)
{
	write(singleton()->tty, &c, 1);
	return (1);
}

static int			ft_putnstr_fd(char *value, size_t n, int fd)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		write(fd, &value[i], 1);
		i++;
		if (!value[i])
			break ;
	}
	return (1);
}

static int			ft_printbis(int offset, int j)
{
	tputs(tgoto(tgetstr("cm", NULL), offset, j), 1, ft_putcharslct);
	if (singleton()->clst == singleton()->current)
		tputs(tgetstr("us", NULL), 1, ft_putcharslct);
	if (singleton()->clst->selected == TRUE)
		tputs(tgetstr("mr", NULL), 1, ft_putcharslct);
	if (singleton()->winsz->ws_col - offset > 0)
		ft_putnstr_fd(singleton()->clst->value,
				(singleton()->winsz->ws_col - offset), singleton()->tty);
	tputs(tgetstr("ue", NULL), 1, ft_putcharslct);
	tputs(tgetstr("me", NULL), 1, ft_putcharslct);
	return (1);
}

int					ft_printclst(void)
{
	int				i;
	int				j;
	int				offset;

	i = 0;
	j = 0;
	offset = 0;
	while (!singleton()->clst->first || i == 0)
	{
		ft_printbis(offset, j);
		singleton()->clst = singleton()->clst->next;
		if (singleton()->clst->first)
			i = 1;
		j++;
		if (j == singleton()->winsz->ws_row)
		{
			j = 0;
			offset += singleton()->maxlen + 2;
		}
	}
	return (1);
}

void				ft_returnslct(void)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (!singleton()->clst->first || j == 0)
	{
		if (i)
			ft_putchar(' ');
		if (singleton()->clst->selected)
		{
			ft_putstr(singleton()->clst->value);
			i = 1;
		}
		singleton()->clst = singleton()->clst->next;
		if (singleton()->clst->first)
			j = 1;
	}
	ft_reset();
}
