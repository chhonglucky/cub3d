/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangjaehyun <kangjaehyun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:32:29 by kangjaehyun       #+#    #+#             */
/*   Updated: 2024/11/11 14:48:00 by kangjaehyun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strip(char *line)
{
	char	*str;

	if (line && line[0] == '\n' && line[1] == 0)
	{
		free(line);
		return (0);
	}
	str = ft_strtrim(line, "\n");
	free(line);
	return (str);
}