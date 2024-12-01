/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:13:18 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:13:19 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static int	is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int			check_arr_input(char *nbr)
{
	if (!is_number(nbr) || !ft_isinteger(nbr))
		return (1);
	return (0);
}
