/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:43:19 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/20 13:47:27 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(t_backup **b, char **temp, char *line)
{
	if (temp)
	{
		if (*temp)
		{
			free(*temp);
			*temp = 0;
		}
	}
	if (b)
	{
		if (*b)
		{
			if ((*b)->buf)
			{
				free((*b)->buf);
				(*b)->buf = 0;
			}
			free(*b);
			*b = 0;
		}
	}
	return (line);
}

t_backup	*update_backup(t_backup **backup)
{
	char	*new;
	ssize_t	i;

	i = 0;
	while (((*backup)->buf)[i] != '\n' && ((*backup)->buf)[i] != '\0')
		i++;
	if (((*backup)->buf)[i] != '\n')
	{
		((*backup)->buf)[0] = 0;
		return (*backup);
	}
	i++;
	(*backup)->save = 0;
	while (((*backup)->buf)[i + (*backup)->save] != '\0')
		(*backup)->save += 1;
	(*backup)->total = BUFFER_SIZE;
	while ((*backup)->total < (*backup)->save)
		(*backup)->total *= 2;
	new = (char *) malloc(sizeof(char) * ((*backup)->total + 1));
	if (new == 0)
		return (0);
	new = ft_strcpy(new, (*backup)->buf, 0);
	free((*backup)->buf);
	(*backup)->buf = new;
	return (*backup);
}

t_backup	*reset_backup(t_backup **backup)
{
	if (*backup)
		return (*backup);
	*backup = (t_backup *) malloc(sizeof(t_backup));
	if (*backup == 0)
		return (0);
	(*backup)->buf = (char *) malloc(sizeof(char) * ((size_t) BUFFER_SIZE + 1));
	if (!((*backup)->buf))
		return (0);
	((*backup)->buf)[0] = '\0';
	(*backup)->save = 0;
	(*backup)->total = BUFFER_SIZE;
	return (*backup);
}

int	ft_strf(char *dest, char *src)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	if (!dest)
	{
		while (src[i])
		{
			if (src[i++] == '\n')
				return (1);
		}
		return (0);
	}
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (1);
}

char	*ft_strcpy(char *dest, char *src, int which_backup)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	if (which_backup == 1)
	{
		while (src[i] != '\0' && src[i] != '\n')
		{
			dest[i] = src[i];
			i++;
		}
		if (src[i] == '\n')
			dest[i++] = '\n';
		dest[i] = '\0';
		return (dest);
	}
	j = -1;
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	while (src[i + (++j)])
		dest[j] = src[i + j];
	dest[j] = '\0';
	return (dest);
}
