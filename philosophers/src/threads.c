/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:58 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/28 16:54:59 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	*routine(void *param)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	i = 0;
	philo = (t_philo *)param;
	data = philo->data;
	if (philo->pos % 2 && data->count > 1)
		ft_sleep(data->time_to_eat / 50, data);
	while (!data->stop_condition && !data->max_ate)
	{
		philo_eat(philo);
		philo_print("is sleeping", philo, UNLOCK);
		ft_sleep(data->time_to_sleep, data);
		philo_print("is thinking", philo, UNLOCK);
	}
	return (NULL);
}

static void	exit_threads(t_data *data)
{
	int	i;

	if (data->count == 1)
		pthread_detach(data->philos[0].thread_id);
	else
	{
		i = -1;
		while (++i < data->count)
			pthread_join(data->philos[i].thread_id, NULL);
	}
	i = -1;
	while (++i < data->count)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->writing);
	i = -1;
	while (++i < data->count)
		free(data->philos[i].pos_str);
	free(data->philos);
	free(data->forks);
}

int	start_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time();
	while (++i < data->count)
	{
		data->philos[i].last_ate = get_time();
		if (pthread_create(&data->philos[i].thread_id,
				NULL, routine, &(data->philos[i])))
			return (0);
	}
	philo_dead(data, data->philos);
	pthread_mutex_unlock(&data->writing);
	exit_threads(data);
	return (1);
}
