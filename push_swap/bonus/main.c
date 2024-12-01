/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:15 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:15 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static int	ft_error(int *tab, int *move)
{
	free(tab);
	free(move);
	write(2, "Error\n", 6);
	return (1);
}

static int	ft_stack_sorted(t_stack stack)
{
	int	index;

	index = 0;
	while (index < stack.size - 1)
	{
		if (stack.arr[index] > stack.arr[index + 1])
			return (0);
		++index;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*instructions;

	if (argc > 1)
	{
		stack.arr = parse_arg(&argc, argv);
		if (!stack.arr)
			return (ft_error(0, 0));
		stack.size = argc - 1;
		instructions = ft_read();
		if (!instructions)
			return (ft_error(stack.arr, 0));
		if (ft_move(&stack, instructions))
			return (ft_error(stack.arr, instructions));
		if (stack.size == argc - 1 && ft_stack_sorted(stack))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		free(stack.arr);
		free(instructions);
	}
	return (0);
}
