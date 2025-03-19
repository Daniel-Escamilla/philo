/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:46:34 by descamil          #+#    #+#             */
/*   Updated: 2025/03/19 09:47:00 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

t_philo	*ft_init_threads(t_times *time, int i)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;

	philos = ft_calloc(time->number_philos, sizeof(t_philo));
	if (!philos)
		return (NULL);
	forks = ft_calloc(sizeof(pthread_mutex_t), time->number_philos);
	if (!forks)
	{
		free(philos);
		return (NULL);
	}
	while (i < time->number_philos)
		pthread_mutex_init(&forks[i++], NULL);
	i = -1;
	while (++i < time->number_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = get_timestamp();
		philos[i].time = *time;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % time->number_philos];
	}
	return (philos);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, FORK);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal_time = get_timestamp();
		philo->meals_eaten += 1;
		pthread_mutex_unlock(&philo->meal_mutex);
		ft_print_status(philo, EATING);
		usleep(philo->time.time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_print_status(philo, SLEEPING);
		usleep(philo->time.time_to_sleep * 1000);
		ft_print_status(philo, THINKING);
	}
	return (NULL);
}

pthread_t	*ft_create_threads(t_philo *philos)
{
	pthread_t	*threads;
	int			num;
	int			i;

	num = philos->time.number_philos;
	threads = ft_calloc(sizeof(pthread_t), num);
	if (!threads)
		return (NULL);
	i = 0;
	while (i < num)
	{
		if (pthread_create(&threads[i], NULL,
				philosopher_routine, &philos[i]) != 0)
		{
			free(threads);
			return (NULL);
		}
		i++;
	}
	return (threads);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		finished_philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		finished_philos = 0;
		while (i < philos->time.number_philos)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (get_timestamp() - philos[i].last_meal_time
				> philos->time.time_to_die)
				exit(ft_print_status(&philos[i], DIED));
			if (philos->time.eat_limit > 0
				&& philos[i].meals_eaten == philos->time.eat_limit)
				finished_philos++;
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
		if (finished_philos == philos->time.number_philos)
			exit(0);
		usleep(1000);
	}
}

int	execute_threads(t_times *time, int i)
{
	pthread_t	*threads;
	pthread_t	monitor;
	t_philo		*philos;

	philos = ft_init_threads(time, 0);
	if (!philos)
		return (1);
	threads = ft_create_threads(philos);
	if (!threads)
	{
		ft_free_philo(philos);
		return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos) != 0)
	{
		free(threads);
		ft_free_philo(philos);
		return (1);
	}
	while (i < time->number_philos)
		pthread_join(threads[i++], NULL);
	pthread_join(monitor, NULL);
	free(threads);
	ft_free_philo(philos);
	return (0);
}
