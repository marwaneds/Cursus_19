/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:12 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:12 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static void	ft_rotate(t_stack *stack)
{
	int	index;
	int	save;

	index = 0;
	save = stack->arr[index];
	while (index < stack->size - 1)
	{
		stack->arr[index] = stack->arr[index + 1];
		++index;
	}
	stack->arr[index] = save;
}

static void	ft_rrotate(t_stack *stack)
{
	int	index;
	int	save;

	index = stack->size - 1;
	save = stack->arr[index];
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		--index;
	}
	stack->arr[index] = save;
}

static void	ft_pushstack(t_stack *dst, t_stack *src)
{
	int	index;

	index = dst->size;
	while (index > 0)
	{
		dst->arr[index] = dst->arr[index - 1];
		--index;
	}
	dst->arr[0] = src->arr[0];
	while (index < src->size - 1)
	{
		src->arr[index] = src->arr[index + 1];
		++index;
	}
	++(dst->size);
	--(src->size);
}

static void	ft_swap(int *tab)
{
	int	save;

	save = tab[1];
	tab[1] = tab[0];
	tab[0] = save;
}

void	ft_operation(t_stack *stack_a, t_stack *stack_b, int operation)
{
	if (operation == SA)
		ft_swap(stack_a->arr);
	else if (operation == SB)
		ft_swap(stack_b->arr);
	else if (operation == PA)
		ft_pushstack(stack_a, stack_b);
	else if (operation == PB)
		ft_pushstack(stack_b, stack_a);
	else if (operation == RA)
		ft_rotate(stack_a);
	else if (operation == RB)
		ft_rotate(stack_b);
	else if (operation == RRA)
		ft_rrotate(stack_a);
	else if (operation == RRB)
		ft_rrotate(stack_b);
}
