/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:56:13 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/07 17:15:25 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char ch, int fd)
{
	unsigned char	c;

	c = (unsigned char) ch;
	if (fd >= 0)
		write(fd, &c, 1);
}
