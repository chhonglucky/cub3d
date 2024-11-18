/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:00:51 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/11 14:42:51 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c);
static char		*ft_dup(char const *str, char c, int *flag);
static char		**ft_allocate_list(char const *s, char c, size_t *a, size_t *b);
static void		ft_free(char **result);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	index;
	int		flag;

	result = ft_allocate_list(s, c, &i, &index);
	if (result == 0)
		return (0);
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			result[index++] = ft_dup(&s[i], c, &flag);
			if (result[index - 1] == 0)
			{
				ft_free(result);
				return (0);
			}
		}
		i++;
	}
	return (result);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_dup(char const *str, char c, int *flag)
{
	size_t	i;
	char	*result;

	i = 0;
	*flag = 1;
	while (str[i] != c && str[i])
		i++;
	result = (char *) malloc(i + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (str[i] != c && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	**ft_allocate_list(char const *s, char c, size_t *a, size_t *b)
{
	char	**result;
	size_t	count;

	*a = 0;
	*b = 0;
	if (s == 0)
		return (0);
	count = ft_count(s, c);
	result = (char **) malloc(sizeof(char *) * (count + 1));
	if (result == 0)
		return (0);
	result[count] = 0;
	return (result);
}

static void	ft_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}
