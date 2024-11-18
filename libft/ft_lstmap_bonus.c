/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:20 by jae-kang          #+#    #+#             */
/*   Updated: 2023/10/11 11:39:49 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	void	*temp;

	result = 0;
	if (lst == 0 || del == 0 || f == 0)
		return (0);
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (new == 0)
		{
			del(temp);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
