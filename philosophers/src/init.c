/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:08 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/28 16:55:09 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->meal, NULL))
		return (1);
	if (pthread_mutex_init(&data->writing, NULL))
		return (1);
	return (0);
}

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		data->philos[i].ate_time = 0;
		data->philos[i].pos = i + 1;
		data->philos[i].pos_str = ft_itoa(i + 1);
		if (!data->philos[i].pos_str)
			break ;
		data->philos[i].ffork = i;
		data->philos[i].sfork = (i + 1) % data->count;
		data->philos[i].data = data;
		i++;
	}
	if (i != data->count)
	{
		while (i >= 0)
		{
			free(data->philos[i].pos_str);
			i--;
		}
		return (1);
	}
	return (0);
}

int	init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->count);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
	if (init_mutex(data))
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	if (init_philo(data))
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	return (1);
}
