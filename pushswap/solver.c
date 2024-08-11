/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:34:05 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:33:27 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solver(t_frame *frame)
{
	if (!(sorted(frame)))
	{
		if (find_stack_len(frame, 'a') <= 5)
			solve_max_5(frame);
		else if (find_stack_len(frame, 'a') <= 100)
			insertion_solve_half(frame);
		else
			insertion_solve_quarters(frame);
	}
}
