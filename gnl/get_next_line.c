/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:39:26 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/20 13:48:03 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_backup		*bu;
	char				*temp;
	ssize_t				n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = (char *) malloc(sizeof(char) * ((size_t) BUFFER_SIZE + 1));
	if (!temp)
		return (free_all(&bu, &temp, 0));
	n = read(fd, temp, BUFFER_SIZE);
	while (n >= 0)
	{
		if (!reset_backup(&bu))
			break ;
		if ((!n && !(bu->save)) || !(save(&bu, n, &temp)))
			break ;
		if (ft_strf(0, bu->buf) || (!(ft_strf(0, bu->buf)) && n < BUFFER_SIZE))
			return (extract(&bu, n, &temp));
		n = read(fd, temp, BUFFER_SIZE);
	}
	return (free_all(&bu, &temp, 0));
}

char	*save(t_backup **backup, ssize_t n, char **temp)
{
	char	*new;
	ssize_t	i;

	if (n == 0)
		return ("1");
	(*temp)[n] = '\0';
	(*backup)->save += n;
	new = 0;
	if ((*backup)->save > (*backup)->total)
	{
		new = (char *) malloc(sizeof(char) * (((*backup)->total) * 2 + 1));
		if (new == 0)
			return (0);
		i = -1;
		while (((*backup)->buf)[++i])
			new[i] = ((*backup)->buf)[i];
		new[i] = '\0';
		free((*backup)->buf);
		(*backup)->buf = new;
		(*backup)->total *= 2;
	}
	ft_strf((*backup)->buf, *temp);
	return ("1");
}

char	*extract(t_backup **backup, ssize_t n, char **temp)
{
	char	*line;
	ssize_t	i;

	i = 0;
	while (((*backup)->buf)[i] != '\0' && ((*backup)->buf)[i] != '\n')
		i++;
	if (((*backup)->buf)[i] == '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 1));
	if (line == 0)
		return (free_all(backup, temp, 0));
	line = ft_strcpy(line, (*backup)->buf, 1);
	if (update_backup(backup) == 0)
	{
		free(line);
		return (free_all(backup, temp, 0));
	}
	if (!(ft_strf(0, line)) || (n < BUFFER_SIZE && !(((*backup)->save))))
		return (free_all(backup, temp, line));
	free(*temp);
	return (line);
}
