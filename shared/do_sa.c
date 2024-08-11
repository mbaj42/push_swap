/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:59:35 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:43:15 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa(t_frame *frame)
{
	long int	tmp;

	if (frame->a && frame->a->next != frame->a)
	{
		tmp = frame->a->num;
		frame->a->num = frame->a->next->num;
		frame->a->next->num = tmp;
	}
	if (frame->do_write)
		write(1, "sa\n", 3);
}
