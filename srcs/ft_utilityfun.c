/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilityfun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:19:55 by tdieumeg          #+#    #+#             */
/*   Updated: 2016/03/25 18:40:16 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_select.h"

void				ft_callreset(int sig)
{
	(void)sig;
	ft_reset();
}

void				ft_suspend(int sig)
{
	char		cp[2] = {singleton()->term->c_cc[VSUSP], 0};

	if (sig == SIGTSTP)
	{
		tputs(tgetstr("ve", NULL), 1, ft_putcharslct);
		tputs(tgetstr("te", NULL), 1, ft_putcharslct);
		tcgetattr(0, singleton()->term);
		singleton()->term->c_lflag |= (ICANON | ECHO);
		tcsetattr(0, 0, singleton()->term);
		close(singleton()->tty);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGCONT, ft_continue);
		ioctl(0, TIOCSTI, cp);
	}
}

void				ft_continue(int sig)
{
	if (sig == SIGCONT)
	{
		singleton()->tty = open(ttyname(0), O_WRONLY);
		singleton()->term->c_lflag &= ~(ICANON | ECHO);
		singleton()->term->c_cc[VMIN] = 1;
		singleton()->term->c_cc[VTIME] = 0;
		tcsetattr(0, TCSADRAIN, singleton()->term);
		tputs(tgetstr("ti", NULL), 1, ft_putcharslct);
		tputs(tgetstr("vi", NULL), 1, ft_putcharslct);
		ft_printclst();
		signal(SIGTSTP, ft_suspend);
	}
}

void				ft_resize(int sig)
{
	if (sig == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, singleton()->winsz);
		tputs(tgetstr("te", NULL), 1, ft_putcharslct);
		tputs(tgetstr("ti", NULL), 1, ft_putcharslct);
		ft_printclst();
	}
}

t_clst				*ft_getav(int ac, char **av)
{
	t_clst			*clst;
	int				i;
	unsigned int	maxlen;

	clst = NULL;
	i = 1;
	maxlen = 0;
	while (i < ac)
	{
		clst = ft_clstpush(av[i], &clst, 0);
		i++;
	}
	ft_getmax(clst);
	return (clst);
}
