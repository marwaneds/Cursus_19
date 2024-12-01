/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:21 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/28 16:55:22 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERROR_USAGE "Usage: ./philo <# philosophers> <time to die> <time to eat>\
 <time to sleep> [# times each philosopher must eat]\n"
# define UNLOCK 1
# define LOCK 0

struct	s_data;

typedef struct s_philo
{
	int				ate_time;
	int				pos;
	char			*pos_str;
	int				ffork;
	int				sfork;
	unsigned long	last_ate;
	struct s_data	*data;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_data
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count_max;
	unsigned long	start_time;
	int				stop_condition;
	int				max_ate;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}				t_data;

int				ft_atoi(const char *nptr);
int				ft_error(char *msg);
int				ft_strlen(char *str);
char			*ft_itoa(int nbr);
int				ft_isint(const char *nptr);
int				init(t_data *data);
void			philo_print(char *msg, t_philo *philo, int unlock);
void			philo_eat(t_philo *philo);
void			philo_dead(t_data *data, t_philo *philo);
int				start_threads(t_data *data);
unsigned long	get_time(void);
void			ft_sleep(unsigned long duration, t_data *data);

#endif