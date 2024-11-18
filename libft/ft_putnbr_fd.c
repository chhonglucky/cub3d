/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:59:53 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/09 15:41:54 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n);
static int	ft_ten(int size);
static void	ft_positive_putnbr_fd(int n, int size, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	size;

	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		size = ft_size(n);
		ft_positive_putnbr_fd(n, size, fd);
	}
}

static int	ft_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_ten(int size)
{
	int	ten;
	int	i;

	ten = 1;
	i = 1;
	while (i < size)
	{
		ten *= 10;
		i++;
	}
	return (ten);
}

static void	ft_positive_putnbr_fd(int n, int size, int fd)
{
	int		div;
	char	c;

	div = ft_ten(size);
	while (div >= 1)
	{
		c = '0' + n / div;
		write(fd, &c, 1);
		n %= div;
		div /= 10;
	}
}
