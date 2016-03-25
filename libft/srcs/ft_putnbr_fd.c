/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:49:36 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/02/28 10:59:28 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	if (nb >= 10)
		ft_putunbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putunbr_fd((unsigned int)-nb, fd);
	}
	else
		ft_putunbr_fd((unsigned int)nb, fd);
}
