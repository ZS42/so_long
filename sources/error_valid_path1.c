/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_valid_path1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:09:58 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/21 14:23:39 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_queue	*ft_lstnew_dl(int content)
{
	t_queue	*new;

	new = ft_calloc(1, sizeof(t_queue));
	if (new == NULL)
		return (0);
	new -> content = content;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_queue	*ft_lstadd_back_dl(t_queue **queue, t_queue *new)
{
	t_queue	*ptr;

	if (new == NULL)
		return (*queue);
	ptr = *queue;
	if (!ptr)
		ptr = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	return (*queue);
}

void	*ft_dequeue(t_queue *enqueue)
{
	enqueue->next = NULL;
	del (enqueue);
	return (NULL);
}
