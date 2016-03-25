/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:24:32 by tdieumeg          #+#    #+#             */
/*   Updated: 2016/03/25 18:28:29 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				FT_SELECT_H
# define			FT_SELECT_H

# include			<term.h>
# include			<termios.h>
# include			<fcntl.h>
# include			<signal.h>
# include			<sys/ioctl.h>
# include			"libft.h"

# define			UP_ARROW 4283163
# define			DOWN_ARROW 4348699
# define			RIGHT_ARROW 4414235
# define			LEFT_ARROW 4479771
# define			SPACE 32
# define			DELETE 2117294875
# define			BACKSPACE 127
# define			RETURN 10
# define			ESCAPE 27

typedef struct		termios t_termios;
typedef struct		winsize t_winsize;

typedef struct		s_singleton
{
	t_clst			*clst;
	t_clst			*current;
	t_termios		*term;
	t_winsize		*winsz;
	int				tty;
	int				maxlen;
}					t_singleton;

/*
** ft_utilityfun.c
*/
void				ft_callreset(int sig);
void				ft_suspend(int sig);
void				ft_continue(int sig);
void				ft_resize(int sig);
t_clst				*ft_getav(int ac, char **av);

/*
** ft_utilityfun2.c
*/
int					ft_getmax(t_clst *clst);
int					ft_clstsize(t_clst *clst);
int					ft_currentidx(t_clst *clst, t_clst *current);

/*
** ft_termfun.c
*/
t_singleton			*singleton(void);
int					ft_start(void);
int					ft_reset(void);

/*
** ft_printfun.c
*/
int					ft_putcharslct(int c);
int					ft_printclst(void);
void				ft_returnslct(void);

/*
** ft_keycmp.c
*/
int					ft_keycmp(int buffer);

#endif				/* !FT_SELECT_H */
