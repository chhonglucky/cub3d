/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:19:03 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/09 15:39:25 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move(unsigned char *d, unsigned char *s, size_t num, int l2r);

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (num == 0)
		return (dest);
	if (dest < src)
		ft_move(d, s, num, 1);
	else
		ft_move(d, s, num, -1);
	return ((void *) d);
}

static void	ft_move(unsigned char *d, unsigned char *s, size_t num, int l2r)
{
	size_t	i;

	if (l2r == 1)
	{
		i = 0;
		while (i < num)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = num;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
}
