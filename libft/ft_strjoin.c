/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:19:35 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/11 13:22:24 by kangjaehyun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (result == 0)
		return (0);
	ft_strlcpy(result, (const char *)s1, len1 + 1);
	ft_strlcat(result, (const char *)s2, len1 + len2 + 1);
	return (result);
}
