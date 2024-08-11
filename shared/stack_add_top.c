/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:04:58 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 22:00:28 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_add_top(t_frame *frame, char stack_name, int num)
{
	t_stack	**top;
	t_stack	*new_node;

	if (stack_name == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		push_swap_error(frame);
	new_node->num = num;
	if (*top == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*top = new_node;
	}
	else
	{
		new_node->next = *top;
		new_node->prev = (*top)->prev;
		(*top)->prev->next = new_node;
		(*top)->prev = new_node;
		*top = new_node;
	}
}
