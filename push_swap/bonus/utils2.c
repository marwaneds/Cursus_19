/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:58 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/13 13:39:00 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

long	ft_atoi(const char *str)
{
	int		index;
	int		sign;
	long	res;
	long	save;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index ++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index ++] == '-')
			sign *= -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = res;
		res = res * 10 + str[index ++] - '0';
		if (res < save)
			return (save);
	}
	return (res * sign);
}

int	ft_tablen(char **tab)
{
	int	res;

	res = 0;
	if (!tab)
		return (0);
	while (tab[res])
		++res;
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index ++;
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}
