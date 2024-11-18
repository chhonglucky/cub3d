/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:27:19 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/13 12:21:27 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dest == 0 && source == 0)
		return (0);
	if (dest == source)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned char *) source;
	i = 0;
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *) d);
}
