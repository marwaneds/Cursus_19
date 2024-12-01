/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:41 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/12 17:28:18 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_tab(int i, int len, int *tab, char **args)
{
	while (i < len)
	{
		if (!args[i])
			return ;
		tab[i] = atoi(args[i]);
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			exit_error(NULL, NULL);
		i++;
	}
}

int	have_dubble(int len, char **args)
{
	int	i;
	int	j;
	int	*tab;

	j = 0;
	tab = (int *)malloc(sizeof(int) * len);
	init_tab(0, len, tab, args);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}

int	have_dubble1(int len, char **args)
{
	int	i;
	int	j;
	int	*tab;

	j = 0;
	tab = (int *)malloc(sizeof(int) * len);
	init_tab(1, len, tab, args);
	i = 1;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}
