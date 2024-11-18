/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:28:08 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/08 19:10:33 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *) buf;
	i = 0;
	while (i < count)
	{
		if (b[i] == (unsigned char) c)
			return ((void *)buf + i);
		i++;
	}
	return (0);
}
