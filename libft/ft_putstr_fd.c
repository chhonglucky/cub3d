/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:56:06 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/07 17:47:48 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t			size;
	unsigned char	*s;

	if (str == 0)
		return ;
	s = (unsigned char *) str;
	size = ft_strlen((char *) s);
	if (fd >= 0 && size > 0)
		write(fd, s, size);
}
