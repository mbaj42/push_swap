/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:37:31 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 20:47:00 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

static void	find_median(t_frame *frame, t_stack *stack, char stack_name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	frame->stack_len = find_stack_len(frame, stack_name);
	quarter_len = frame->stack_len / 4;
	array = (long *)malloc(sizeof(long) * (frame->stack_len + 1));
	if (!array)
	{
		push_swap_error(frame);
		return ;
	}
	while (i < frame->stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	sort_array(array, frame->stack_len);
	frame->quarter = array[quarter_len];
	frame->median = array[quarter_len * 2];
	frame->three_quarters = array[quarter_len * 3];
	free(array);
}

void	median(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	find_median(frame, stack, stack_name);
}
