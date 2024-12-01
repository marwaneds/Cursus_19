/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:03 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/28 16:55:04 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	check_params(t_data *data, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_count_max = ft_atoi(argv[5]);
	else
		data->eat_count_max = 0;
	if (data->count < 1 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->eat_count_max < 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.max_ate = 0;
	data.stop_condition = 0;
	if (argc < 5 || argc > 6)
		return (ft_error(ERROR_USAGE));
	if (!check_params(&data, argc, argv))
		return (ft_error("Incorrect parameters\n"));
	if (!init(&data))
		return (ft_error("init error.\n"));
	if (!start_threads(&data))
		return (ft_error("threads error.\n"));
	return (0);
}
