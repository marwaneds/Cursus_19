/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:26:38 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/13 14:37:30 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (!str || str[0] == '\0')
		exit_error(NULL, NULL);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	if (!is_digit(str[i]))
		exit_error(NULL, NULL);
	while (is_digit(str[i]))
		nb = (nb * 10) + (str[i++] - '0');
	if (str[i])
		exit_error(NULL, NULL);
	return (nb * isneg);
}

/* ft_putstr:
*	Prints a given string of characters to the standard output.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
