/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:38:33 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 18:41:07 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		if ((n / 10) > 0)
		{
			ft_putnbr(n / 10, fd);
			ft_putnbr(n % 10, fd);
		}
		else
		{
			c = n + '0';
			write(fd, &c, 1);
		}
	}
}