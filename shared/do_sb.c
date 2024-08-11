/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:59:48 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:43:36 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sb(t_frame *frame)
{
	long int	tmp;

	if (frame->b && frame->b->next != frame->b)
	{
		tmp = frame->b->num;
		frame->b->num = frame->b->next->num;
		frame->b->next->num = tmp;
	}
	if (frame->do_write)
		write(1, "sb\n", 3);
}
