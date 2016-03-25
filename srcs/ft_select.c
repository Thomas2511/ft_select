/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 13:07:31 by tdieumeg          #+#    #+#             */
/*   Updated: 2016/03/25 18:33:04 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_select.h"

int					main(int ac, char **av)
{
	char			*term_name;

	if ((singleton()->clst = ft_getav(ac, av)) == NULL)
		return (ft_putendl_fd("usage: ./ft_select [arg1][...]", 2));
	if (!(term_name = getenv("TERM")))
		return (ft_putendl_fd("ft_select: restore env before execution", 2));
	tgetent(NULL, term_name);
	ioctl(0, TIOCGWINSZ, singleton()->winsz);
	tcgetattr(0, singleton()->term);
	signal(SIGWINCH, ft_resize);
	signal(SIGINT, ft_callreset);
	signal(SIGTERM, ft_callreset);
	signal(SIGKILL, ft_callreset);
	signal(SIGQUIT, ft_callreset);
	signal(SIGTSTP, ft_suspend);
	signal(SIGCONT, ft_continue);
	ft_start();
	ft_reset();
	return (0);
}
