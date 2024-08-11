/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:38:11 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:06:25 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_stack_len(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack	*end;
	int		len;

	len = 0;
	if (stack_name == 'a')
	{
		stack = frame->a;
		end = frame->a->prev;
	}
	else
	{
		stack = frame->b;
		end = frame->b->prev;
	}
	while (stack)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (len);
}
