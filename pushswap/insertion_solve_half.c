/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:39:28 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:09:00 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_and_push_to_a(t_frame *frame)
{
	if (frame->small_rotate >= 0)
		while (frame->small_rotate--)
			do_rb(frame);
	else if (frame->small_rrotate >= 0)
		while (frame->small_rrotate--)
			do_rrb(frame);
	else if (frame->big_rotate >= 0)
		while (frame->big_rotate--)
			do_rb(frame);
	else if (frame->big_rrotate >= 0)
		while (frame->big_rrotate--)
			do_rrb(frame);
	do_pa(frame);
	if (frame->small_flag)
		do_ra(frame);
	if (frame->big_flag || !frame->b)
		frame->after_rotate++;
	reset_moves(frame);
}

static void	push_big_small(t_frame *frame, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->num != frame->smallest && stack->num != frame->biggest)
			stack = stack->next;
		if (stack->num == frame->smallest || stack->num == frame->biggest)
		{
			rotate_and_push_to_a(frame);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = frame->b;
	}
}

void	insertion_solve_half(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a');
	while (frame->a)
	{
		push_median(frame, split);
		while (frame->b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->b && (frame->small_rotate >= 0
					|| frame->small_rrotate >= 0
					|| frame->big_rotate >= 0 || frame->big_rrotate >= 0))
				push_big_small(frame, frame->b, frame->b->prev);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 3)
			break ;
	}
}
