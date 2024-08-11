/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:55:33 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:39:27 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pb(t_frame *frame)
{
	long int	tmp;

	if (frame->a)
	{
		tmp = frame->a->num;
		stack_del_top(frame, 'a');
		stack_add_top(frame, 'b', tmp);
	}
	if (frame->do_write)
		write(1, "pb\n", 3);
}
