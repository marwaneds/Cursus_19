/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:08 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:08 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static int	*ft_free_return(int *tab, char **split)
{
	int	index;

	free(tab);
	if (split)
	{
		index = 0;
		while (split[index])
			free(split[index++]);
		free(split);
	}
	return (0);
}

static int	ft_check_arg(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			if ((str[index] != '-' && str[index] != '+') || index > 0
				|| !str[index + 1])
				return (1);
		}
		++index;
	}
	return (index == 0);
}

static int	ft_duplicate(int *tab, int value, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (tab[index] == value)
			return (1);
		++index;
	}
	return (0);
}

static int	*ft_parse_split(char *str, int *argc)
{
	int		index;
	long	buf;
	char	**argv;
	int		*res;

	argv = ft_split(str, ' ');
	if (!argv)
		return (NULL);
	*argc = ft_tablen(argv) + 1;
	res = malloc(sizeof(*res) * (*argc - 1));
	if (!res)
		return (NULL);
	index = 0;
	while (index < *argc - 1)
	{
		if (ft_check_arg(argv[index]))
			return (ft_free_return(res, argv));
		buf = ft_atoi(argv[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index))
			return (ft_free_return(res, argv));
		res[index++] = buf;
	}
	ft_free_return(NULL, argv);
	return (res);
}

int	*parse_arg(int *argc, char **argv)
{
	int		index;
	int		*res;
	long	buf;

	if (*argc == 2 && ft_check_arg(argv[1]))
		return (ft_parse_split(argv[1], argc));
	res = malloc(sizeof(*res) * (*argc - 1));
	if (!res)
		return (NULL);
	index = 1;
	while (index < *argc)
	{
		if (ft_check_arg(argv[index]))
			return (ft_free_return(res, NULL));
		buf = ft_atoi(argv[index]);
		if (buf > INT_MAX || buf < INT_MIN || ft_duplicate(res, buf, index - 1))
			return (ft_free_return(res, NULL));
		res[index - 1] = buf;
		++index;
	}
	return (res);
}
