/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:36:17 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 17:42:38 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack	*end;

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
	tmp = stack;
	frame->smallest = frame->biggest;
	while (1)
	{
		if (tmp->num <= frame->smallest)
			frame->smallest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

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
	tmp = stack;
	frame->biggest = tmp->num;
	while (1)
	{
		if (tmp->num > frame->biggest)
			frame->biggest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest_smallest(t_frame *frame, char stack_name)
{
	find_biggest(frame, stack_name);
	find_smallest(frame, stack_name);
}
