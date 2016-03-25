/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_endl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 12:55:28 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 10:58:53 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_putnbr_endl_fd(int nb, int fd)
{
	ft_putnbr_fd(nb, fd);
	ft_putchar_fd('\n', fd);
	return (1);
}
