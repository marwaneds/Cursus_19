/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:17 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/13 14:20:01 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort3(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

// static int	affiche(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack)
// 		return (2);
// 	while (stack)
// 	{
// 		printf("ligne %d -> %d\n", i, stack->value);
// 		stack = stack->next;
// 		i++;
// 	}
// 	return (3);
// }

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**args;

	if (argc < 2)
		return (0);
	args = NULL;
	args = parse_arg(args, argv);
	if (!args[0])
		exit_error(NULL, NULL);
	if (!is_correct_input(args) || have_dubble1(argc, argv)
		|| have_dubble(ft_strlen(args), args))
		exit_error(NULL, NULL);
	if (argc == 2)
		stack_a = fill_stack2(ft_strlen(args), args);
	else
		stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
