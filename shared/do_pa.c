/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:55:15 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:38:40 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pa(t_frame *frame)
{
	long int	tmp;

	if (frame->b)
	{
		tmp = frame->b->num;
		stack_del_top(frame, 'b');
		stack_add_top(frame, 'a', tmp);
	}
	if (frame->do_write)
		write(1, "pa\n", 3);
}
