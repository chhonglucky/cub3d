/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:31:49 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/13 12:19:41 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b1 = (unsigned char *) buf1;
	b2 = (unsigned char *) buf2;
	while (i < count)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
