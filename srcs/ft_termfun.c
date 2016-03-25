/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termfun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:54:55 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/11 15:11:08 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include					"ft_select.h"

t_singleton					*singleton(void)
{
	static t_singleton		*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_singleton*)malloc(sizeof(t_singleton));
		singleton->term = (t_termios*)malloc(sizeof(t_termios));
		singleton->winsz = (t_winsize*)malloc(sizeof(t_winsize));
	}
	return (singleton);
}

static int					ft_readkeys(void)
{
	int						buffer;

	while (1)
	{
		tputs(tgetstr("te", NULL), 1, ft_putcharslct);
		tputs(tgetstr("ti", NULL), 1, ft_putcharslct);
		ft_printclst();
		buffer = 0;
		read(0, &buffer, 4);
		ft_keycmp(buffer);
	}
	return (1);
}

int							ft_start(void)
{
	singleton()->tty = open(ttyname(0), O_WRONLY);
	singleton()->term->c_lflag &= ~(ICANON | ECHO);
	singleton()->term->c_cc[VMIN] = 1;
	singleton()->term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, singleton()->term);
	tputs(tgetstr("ti", NULL), 1, ft_putcharslct);
	tputs(tgetstr("vi", NULL), 1, ft_putcharslct);
	singleton()->current = singleton()->clst;
	ft_readkeys();
	return (1);
}

int							ft_reset(void)
{
	tputs(tgetstr("ve", NULL), 1, ft_putcharslct);
	tputs(tgetstr("te", NULL), 1, ft_putcharslct);
	tcgetattr(0, singleton()->term);
	singleton()->term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, singleton()->term);
	close(singleton()->tty);
	exit(EXIT_SUCCESS);
	return (1);
}
