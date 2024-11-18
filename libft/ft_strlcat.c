/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:24:50 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/13 13:28:43 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	if (size == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	if (destlen >= size)
		return (srclen + size);
	j = 0;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
