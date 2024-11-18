/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:31:47 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/08 19:10:30 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	size_t		i;
	int			sign;
	int			num;
	char		*string;

	i = 0;
	num = 0;
	sign = 1;
	string = (char *) s;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == ' ')
		i++;
	if (string[i] == '+' || string[i] == '-')
		if (string[i++] == '-')
			sign *= -1;
	while (string[i] <= '9' && string[i] >= '0')
		num = num * 10 + sign * (string[i++] - '0');
	return (num);
}
