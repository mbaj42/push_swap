/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:36:32 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 22:04:43 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	x(int *a_flag, int *b_flag, t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		*a_flag = 1;
	if (!stack_b)
		*b_flag = 1;
}

void	z(int a_flag, t_stack **stack_a, char **a)
{
	if (!a_flag)
		*a = ft_itoa((*stack_a)->num);
	else
		*a = ft_strdup("");
}

void	s(int b_flag, t_stack **stack_b, char **b)
{
	if (!b_flag)
		*b = ft_itoa((*stack_b)->num);
	else
		*b = ft_strdup("");
}

void	y(t_stack **stack_a, t_stack **stack_b, t_frame *frame)
{
	if (*stack_a && *stack_a != frame->a->prev)
		*stack_a = (*stack_a)->next;
	else
		*stack_a = NULL;
	if (*stack_b && *stack_b != frame->b->prev)
		*stack_b = (*stack_b)->next;
	else
		*stack_b = NULL;
}
