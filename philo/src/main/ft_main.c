/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:08:52 by descamil          #+#    #+#             */
/*   Updated: 2025/03/18 12:53:58 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

long	get_timestamp()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_print_status(t_philo *philo, int msg_type)
{
	long				timestamp;
	static const char	*messages[] = {
		" is eating\n",
		" is sleeping\n",
		" has taken a fork\n",
		" is thinking\n",
		" must eat count reached\n",
		" died\n"
	};

	if (msg_type < 0 || msg_type > 5)
		return;
	timestamp = get_timestamp() - philo->time.start_time;
	pthread_mutex_lock(&philo->print_mutex);
	printf("%ld %d%s", timestamp, philo->id, messages[msg_type]);
	pthread_mutex_unlock(&philo->print_mutex);
}

void	ft_free_philo(t_philo *philos)
{
	int	i;

	if (!philos)
		return;
	i = 0;
	while (i < philos[0].time.number_philos)
	{
		pthread_mutex_destroy(&philos[i].meal_mutex);
		pthread_mutex_destroy(&philos[i++].print_mutex);
	}
	free(philos);
}

void	ft_free_time(t_times *time)
{
	if (time)
		free(time);
}

static t_philo *ft_init_threads(t_times *time, int i)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;

	philos = calloc(time->number_philos, sizeof(t_philo));
	if (!philos)
		return (NULL);
	forks = malloc(sizeof(pthread_mutex_t) * time->number_philos);
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
void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (1)
    {
        ft_print_status(philo, THINKING);
        
        /* Alterna el orden de adquisición según el ID del filósofo */
        if (philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            ft_print_status(philo, FORK);
            pthread_mutex_lock(philo->left_fork);
            ft_print_status(philo, FORK);
        }
        else
        {
            pthread_mutex_lock(philo->left_fork);
            ft_print_status(philo, FORK);
            pthread_mutex_lock(philo->right_fork);
            ft_print_status(philo, FORK);
        }
        
        /* Una vez que tiene ambos tenedores, actualiza last_meal_time */
        pthread_mutex_lock(&philo->meal_mutex);
        philo->last_meal_time = get_timestamp();
        pthread_mutex_unlock(&philo->meal_mutex);
        
        ft_print_status(philo, EATING);
        usleep(philo->time.time_to_eat * 1000);
        
        /* Suelta los tenedores */
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        
        ft_print_status(philo, SLEEPING);
        usleep(philo->time.time_to_sleep * 1000);
    }
    return (NULL);
}




pthread_t *ft_create_threads(t_philo *philos)
{
    pthread_t *threads;
    int i;
    int num;

    num = philos->time.number_philos;
    threads = malloc(sizeof(pthread_t) * num);
    if (!threads)
        return (NULL);
    i = 0;
    while (i < num)
    {
        if (pthread_create(&threads[i], NULL, philosopher_routine, &philos[i]) != 0)
        {
            free(threads);
            return (NULL);
        }
        i++;
    }
    return threads;
}

void *monitor_routine(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < philos->time.number_philos)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			if (get_timestamp() - philos[i].last_meal_time > philos->time.time_to_die)
			{
				ft_print_status(&philos[i], DIED);
				exit(0);
			}
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

static int	ft_return_printf(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int main(int argc, char **argv)
{
	pthread_t	*threads;
	pthread_t	monitor;
	t_philo		*philos;
	t_times		*time;
    int			i;

	i = 0;
	if (argc < 5)
		return(ft_return_printf("Few arguments"));
	if (argc > 6)
		return(ft_return_printf("Too many arguments"));
	time = ft_create_time(argv, argc);
	if (time == NULL)
		return (1);
	time->start_time = get_timestamp();
	time->next_to_eat = 1;
    pthread_mutex_init(&time->turn_mutex, NULL);
	print_times(time);
	philos = ft_init_threads(time, 0);
    if (!philos)
        return (1);
    threads = ft_create_threads(philos);
    if (!threads)
        return (1);
    pthread_create(&monitor, NULL, monitor_routine, philos);
    while (i < time->number_philos)
        pthread_join(threads[i++], NULL);
    pthread_join(monitor, NULL);
    free(threads);
    ft_free_philo(philos);
	return (0);
}
