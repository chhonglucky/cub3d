/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:57:09 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/10 10:24:29 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	size;

	if (s == 0)
		return ;
	size = ft_strlen(s);
	if (fd >= 0)
	{
		write(fd, s, size);
		write(fd, "\n", 1);
	}
}
