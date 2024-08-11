/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:09:25 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:04:46 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	move_frames(stack_name, &stack, frame, &tmp);
	if (flag == 1)
		element = frame->smallest;
	else
		element = frame->biggest;
	if (stack)
	{
		while (tmp->num != element)
		{
			if (flag == 1)
				frame->small_rrotate++;
			else
				frame->big_rrotate++;
			tmp = tmp->prev;
		}
		if (flag == 1)
			frame->small_rrotate++;
		else
			frame->big_rrotate++;
	}
}

static void	moves_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	flag = 1;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->small_rotate <= frame->small_rrotate)
			frame->small_rrotate = -1;
		else
			frame->small_rotate = -1;
	}
}

static void	moves_biggest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	flag = 2;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->big_rotate <= frame->big_rrotate)
			frame->big_rrotate = -1;
		else
			frame->big_rotate = -1;
	}
}

void	find_moves(t_frame *frame, char stack_name)
{
	(void)stack_name;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (frame->big_rotate != -1
		&& (frame->big_rotate >= frame->small_rotate
			&& frame->big_rotate >= frame->small_rrotate))
		frame->big_rotate = -1;
	else if (frame->big_rrotate != -1
		&& (frame->big_rrotate >= frame->small_rotate
			&& frame->big_rrotate >= frame->small_rrotate))
		frame->big_rrotate = -1;
	else if (frame->small_rotate != -1
		&& (frame->small_rotate >= frame->big_rotate
			&& frame->small_rotate >= frame->big_rrotate))
		frame->small_rotate = -1;
	else if (frame->small_rrotate != -1
		&& (frame->small_rrotate >= frame->big_rotate
			&& frame->small_rrotate >= frame->big_rrotate))
		frame->small_rrotate = -1;
	if (frame->small_rotate != -1 || frame->small_rrotate != -1)
		frame->small_flag = 1;
	else if (frame->big_rotate != -1 || frame->big_rrotate != -1)
		frame->big_flag = 1;
}
