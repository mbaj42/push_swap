/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:03:36 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:28:19 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	g(t_frame *frame, int flag, t_stack	*tmp)
{
	if (flag == 1)
		frame->small_rotate++;
	else
		frame->big_rotate++;
	tmp = tmp->next;
}

void	moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	if (stack)
	{
		if (stack_name == 'a')
			tmp = frame->a;
		else
			tmp = frame->b;
		if (flag == 1)
			element = frame->smallest;
		else
			element = frame->biggest;
		while (tmp->num != element)
		{
			g(&frame, flag, &tmp);
		}
	}
}
