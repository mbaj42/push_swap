/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:31:00 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/11 22:45:01 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "srcs/includes/get_next_line.h"
# include "srcs/includes/libft.h"
# include "srcs/includes/printf.h"

typedef struct s_stack
{
	long int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;
	char			**argv;
	char			*line;
	char			*str;
	long			smallest;
	long			biggest;
	long			quarter;
	long			median;
	long			three_quarters;
	int				print_stacks;
	int				do_write;
	int				stack_len;
	int				big_rotate;
	int				big_rrotate;
	int				big_flag;
	int				small_flag;
	int				small_rotate;
	int				small_rrotate;
	int				after_rotate;
}	t_frame;

typedef void	(*t_table)(t_frame *frame);

void	find_moves(t_frame *frame, char stack_name);
void	moves_to_start(t_frame *frame, char stack_name, int flag);
void	move_frames(char stack_name, t_stack **stack,
			t_frame *frame, t_stack **tmp);
void	find_biggest_smallest(t_frame *frame, char stack_name);
void	find_biggest(t_frame *frame, char stack_name);
void	find_smallest(t_frame *frame, char stack_name);
int		find_stack_len(t_frame *frame, char stack_name);
void	insertion_solve_half(t_frame *frame);
void	insertion_solve_quarters(t_frame *frame);
void	median(t_frame *frame, char stack_name);
void	moves_to_end(t_frame *frame, char stack_name, int flag);
void	moves_to_start(t_frame *frame, char stack_name, int flag);
void	push_median(t_frame *frame, int split);
void	push_quarters(t_frame *frame, t_stack *stack_a, int split);
void	push_first_quarter(t_frame *frame);
void	push_second_quarter(t_frame *frame);
void	push_third_quarter(t_frame *frame);
void	push_fourth_quarter(t_frame *frame);
void	reset_moves(t_frame *frame);
void	solve_max_5(t_frame *frame);
void	solver(t_frame *frame);
int		sorted(t_frame *frame);

t_frame	*create_frame(t_frame *frame, char **argv);
void	display_stacks(t_frame *frame);
void	do_pa(t_frame *frame);
void	do_pb(t_frame *frame);
void	do_ra(t_frame *frame);
void	do_rb(t_frame *frame);
void	do_rr(t_frame *frame);
void	do_rra(t_frame *frame);
void	do_rrb(t_frame *frame);
void	do_rrr(t_frame *frame);
void	do_sa(t_frame *frame);
void	do_sb(t_frame *frame);
void	do_ss(t_frame *frame);
void	fill_stack_a(t_frame *frame);
void	push_swap_error(t_frame *frame);
void	push_swap_free(t_frame *frame);
t_stack	**get_stack_top(t_frame *frame, char stack_name);
void	stack_add_end(t_frame *frame, char stack_name, int num);
void	stack_del_top(t_frame *frame, char stack_name);
void	stack_add_top(t_frame *frame, char stack_name, int num);
void	x(int *a_flag, int *b_flag, t_stack *stack_a, t_stack *stack_b);
void	y(t_stack **stack_a, t_stack **stack_b, t_frame *frame);
void	z(int a_flag, t_stack **stack_a, char **a);
void	s(int b_flag, t_stack **stack_b, char **b);
#endif
