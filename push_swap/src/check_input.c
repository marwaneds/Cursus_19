/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:38 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/13 14:34:40 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* arg_is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*   Checks the argument is a 0 to avoid 0 +0 -0 duplicates
*	and 0 0000 +000 -00000000 too.
*   Return: 1 if the argument is a zero, 0 if it contains
*	anything else than a zero.
*/
static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
*   Checks if the given arguments are all numbers,
*	without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/
int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		nb_zeros += arg_is_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}
