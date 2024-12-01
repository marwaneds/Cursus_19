/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:30 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:30 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static void	ft_double(t_stack *stack_a, t_stack *stack_b, int move)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	if (move == SS)
	{
		if (stack_a->size >= 2)
			ft_operation(stack_a, stack_b, SA);
		if (stack_b->size >= 2)
			ft_operation(stack_a, stack_b, SB);
	}
	else if (move == RR)
	{
		if (stack_a->size >= 2)
			ft_operation(stack_a, stack_b, RA);
		if (stack_b->size >= 2)
			ft_operation(stack_a, stack_b, RB);
	}
	else if (move == RRR)
	{
		if (stack_a->size >= 2)
			ft_operation(stack_a, stack_b, RRA);
		if (stack_b->size >= 2)
			ft_operation(stack_a, stack_b, RRB);
	}
}

static void	ft_do_move(t_stack *stack_a, t_stack *stack_b, int move)
{
	if (move == SS || move == RR || move == RRR)
		ft_double(stack_a, stack_b, move);
	else if (move == SA && stack_a->size < 2)
		return ;
	else if (move == SB && stack_b->size < 2)
		return ;
	else if (move == PA && stack_b->size == 0)
		return ;
	else if (move == PB && stack_a->size == 0)
		return ;
	else if (move == RA && stack_a->size < 2)
		return ;
	else if (move == RB && stack_b->size < 2)
		return ;
	else if (move == RRA && stack_a->size < 2)
		return ;
	else if (move == RRB && stack_b->size < 2)
		return ;
	ft_operation(stack_a, stack_b, move);
}

int	ft_move(t_stack *stack_a, int *move)
{
	int		index;
	t_stack	stack_b;

	stack_b.size = 0;
	stack_b.arr = malloc(sizeof(*stack_b.arr) * stack_a->size);
	if (!stack_b.arr)
		return (1);
	index = 0;
	while (move[index] != -1)
		ft_do_move(stack_a, &stack_b, move[index++]);
	free(stack_b.arr);
	return (0);
}
