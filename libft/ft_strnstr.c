/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:49:06 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/13 13:29:04 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp(const char *s1, const char *s2);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	i = 0;
	if (len < 0)
		return (0);
	if (big[0] == 0 && little[0] != 0 && len > 0)
		return (0);
	if (little == 0)
	{
		while (big[i])
			i++;
		return ((char *) big + i);
	}
	ft_cmp(&big[i], little);
	while (i + little_len <= len)
	{
		if (ft_cmp(&big[i], little) == 0)
			return ((char *) big + i);
		i++;
	}
	return (0);
}

int	ft_cmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
