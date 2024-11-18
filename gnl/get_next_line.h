/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:34:36 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/20 17:35:08 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  error BUFFER_SIZE_ERROR
# elif BUFFER_SIZE > 2147483647
#  error BUFFER_SIZE_ERROR
# endif

typedef struct s_backup
{
	ssize_t	total;
	ssize_t	save;
	char	*buf;
}t_backup;

char		*get_next_line(int fd);
char		*save(t_backup **backup, ssize_t count, char **temp);
char		*extract(t_backup **backup, ssize_t n, char **temp);
char		*free_all(t_backup **b, char **str, char *line);
t_backup	*update_backup(t_backup **backup);
t_backup	*reset_backup(t_backup **backup);
int			ft_strf(char *dest, char *src);
char		*ft_strcpy(char *dest, char *src, int which_backup);

#endif
