/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:37:07 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/08 17:11:53 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int chr)
{
	size_t	len;

	len = ft_strlen((const char *) str);
	if (str == 0)
		return (0);
	while (1)
	{
		if ((unsigned char) str[len] == (unsigned char) chr)
			return (str + len);
		if (len == 0)
			break ;
		len--;
	}
	return (0);
}
