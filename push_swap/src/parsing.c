/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:13 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:27:14 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* CHAR ** -----> VOID */
char	**parse_arg(char **args, char **argv)
{
	int	i;

	i = 0;
	args = ft_split(argv[1], ' ');
	return (args);
}

int	ft_strlen(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}
