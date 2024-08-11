/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quaters_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:24:12 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:28:35 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_first_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > frame->quarter / 2)
		do_rb(frame);
	do_pb(frame);
}

void	push_second_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 3)
		do_rb(frame);
	do_pb(frame);
}

void	push_third_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 5)
		do_rb(frame);
	do_pb(frame);
}

void	push_fourth_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 7)
		do_rb(frame);
	do_pb(frame);
}
