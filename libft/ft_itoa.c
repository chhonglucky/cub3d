/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:21 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/09 15:40:15 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_make_str(int n);
static char	*ft_swap(char *n, int len);

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	long long	num;

	i = 0;
	result = ft_make_str(n);
	if (result == 0)
		return (0);
	num = (long long) n;
	if (num == 0)
		result[i++] = '0';
	else if (num < 0)
	{
		num *= -1;
		result[i++] = '-';
	}
	while (num > 0)
	{
		result[i++] = num % 10 + '0';
		num /= 10;
	}
	result[i] = '\0';
	return (ft_swap(result, i - 1));
}

static char	*ft_make_str(int n)
{
	char		*result;
	int			size;
	long long	num;

	size = 0;
	num = (long long) n;
	if (num <= 0)
	{
		size = 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	result = (char *) malloc(size + 1);
	return (result);
}

static char	*ft_swap(char *n, int len)
{
	int		i;
	char	temp;

	i = 0;
	if (n[0] == '0' && n[1] == '\0')
		return (n);
	if (n[0] == '-')
		i++;
	while (i < len)
	{
		temp = n[i];
		n[i++] = n[len];
		n[len--] = temp;
	}
	return (n);
}
