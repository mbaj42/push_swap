/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:54:44 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 21:38:18 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_strings(char *a, char *b)
{
	free(a);
	free(b);
}

static void	display_printf(t_frame *frame, int a_flag, int b_flag)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*a;
	char	*b;

	stack_a = frame->a;
	stack_b = frame->b;
	x(&a_flag, &b_flag, stack_a, stack_b);
	while (1)
	{
		z(a_flag, &stack_a, &a);
		s(b_flag, &stack_b, &b);
		if (!stack_a || stack_a == frame->a->prev)
			a_flag = 1;
		if (!stack_b || stack_b == frame->b->prev)
			b_flag = 1;
		if (!stack_a && !stack_b)
		{
			free_strings(a, b);
			break ;
		}
		ft_printf("%s | s\n", a, b);
		free_strings(a, b);
		y(&stack_a, &stack_b, frame);
	}
}

void	display_stacks(t_frame *frame)
{
	if (frame->print_stacks == 1)
	{
		usleep(100000);
		ft_printf("\E[H\E[2J");
		ft_printf("Stack A				Stack B\n");
		display_printf(frame, 0, 0);
	}
}
