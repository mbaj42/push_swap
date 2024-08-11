/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:35:12 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 22:48:57 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	j(t_stack *stack_a_end, int *flag, t_frame *frame)
{
	stack_a_end = frame->a->prev;
	*flag = 0;
	find_biggest_smallest(frame, 'a');
}

void	push_quarters(t_frame *frame, t_stack *stack_a, int split)
{
	t_stack	*stack_a_end;
	int flag;
	
	j(stack_a_end, &flag, frame);
	while (flag != 1)
	{
		if (stack_a == stack_a_end)
			flag = 1;
		if (split == 1 && stack_a->num <= frame->quarter)
			push_first_quarter(frame);
		else if (split == 2 && stack_a->num > frame->quarter
			&& stack_a->num <= frame->median)
			push_second_quarter(frame);
		else if (split == 3 && stack_a->num > frame->median
			&& stack_a->num <= frame->three_quarters)
			push_third_quarter(frame);
		else if (split == 4 && stack_a->num > frame->three_quarters)
			push_fourth_quarter(frame);
		else if (split == 4 && stack_a->num == frame->smallest)
			break ;
		else
			do_ra(frame);
		stack_a = frame->a;
	}
	reset_moves(frame);
}
