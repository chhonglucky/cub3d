/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:50:31 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/11 13:21:39 by kangjaehyun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_allocate(unsigned int start, size_t len, size_t slen);
void	ft_put(char *str, char const *s, unsigned int start, size_t end);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (s == 0)
		return (0);
	if (start == 0 && len == 0)
	{
		str = (char *) malloc(1);
		if (str == 0)
			return (0);
		str[0] = 0;
		return (str);
	}
	slen = ft_strlen(s);
	str = ft_allocate(start, len, slen);
	if (str == 0)
		return (0);
	if (start < slen && start + len - 1 >= slen)
		ft_put(str, s, start, slen);
	else if (start >= slen)
		str[0] = 0;
	else
		ft_put(str, s, start, start + len);
	return (str);
}

char	*ft_allocate(unsigned int start, size_t len, size_t slen)
{
	char	*str;

	if (start < slen && start + len - 1 >= slen)
	{
		str = (char *) malloc(slen - start + 1);
		if (str == 0)
			return (0);
	}
	else if (start >= slen)
	{
		str = (char *) malloc(1);
		if (str == 0)
			return (0);
	}
	else
	{
		str = (char *) malloc (len + 1);
		if (str == 0)
			return (0);
	}
	return (str);
}

void	ft_put(char *str, char const *s, unsigned int start, size_t end)
{
	size_t	i;

	i = 0;
	while (start + i < end)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
}
