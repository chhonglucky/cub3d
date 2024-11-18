/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:33:39 by jae-kang          #+#    #+#             */
/*   Updated: 2024/11/11 13:22:47 by kangjaehyun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char const *s1, char const *set, size_t size);
static int	ft_check_set(char c, char const *set);
static void	ft_size(char const *s, char const *set, size_t *size);
static char	*empty(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*str;

	if (s1 == 0 || set == 0)
		return (0);
	else if (set == 0)
		return ((char *) s1);
	else if (s1[0] == 0)
		return (empty());
	size = 0;
	ft_size(s1, set, &size);
	str = ft_trim(s1, set, size);
	if (str == 0)
		return (0);
	str[size] = 0;
	if (size == 0)
		return (str);
	return (str);
}

int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_size(char const *s, char const *set, size_t *size)
{
	int		flag;
	size_t	i;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (flag == 0 && ft_check_set(s[i], set) == 1)
			flag = 0;
		else if (flag == 0 && ft_check_set(s[i], set) == 0)
		{
			*size += 1;
			flag = 1;
		}
		else if (flag == 1)
			*size += 1;
		i++;
	}
	while (ft_check_set(s[--i], set))
		*size -= 1;
	if (flag == 0 || s[0] == 0)
		*size = 0;
}

char	*ft_trim(char const *s1, char const *set, size_t size)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	*str;

	i = 0;
	j = 0;
	flag = 0;
	str = (char *) malloc(size + 1);
	if (str == 0)
		return (0);
	while (j < size)
	{
		if (flag == 0 && ft_check_set(s1[i], set) == 1)
			flag = 0;
		else if (flag == 0 && ft_check_set(s1[i], set) == 0)
			flag = 1;
		if (flag == 1)
			str[j++] = s1[i];
		i++;
	}
	return (str);
}

char	*empty(void)
{
	char	*str;

	str = (char *) malloc(1);
	if (!str)
		return (0);
	str[0] = 0;
	return (str);
}
