/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:03:45 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:59:25 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	**get_stack_top(t_frame *frame, char stack_name)
{
	if (stack_name == 'a')
		return (&frame->a);
	else
		return (&frame->b);
}

void	stack_add_end(t_frame *frame, char stack_name, int num)
{
	t_stack	**top;
	t_stack	*new_node;

	top = get_stack_top(frame, stack_name);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		push_swap_error(frame);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*top == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*top = new_node;
	}
	else
	{
		new_node->prev = (*top)->prev;
		new_node->next = *top;
		(*top)->prev->next = new_node;
		(*top)->prev = new_node;
	}
}
