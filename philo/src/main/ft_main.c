/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:08:52 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 13:27:19 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	ft_free_philo(t_philo *philo)
{
	int	i;

	if (!philo)
		return;
	i = 0;
	while (i < philo[0].time.number_philos)
	{
		pthread_mutex_destroy(&philo[i].meal_mutex);
		i++;
	}
	free(philo);
}

void	ft_free_time(t_times *time)
{
	if (time)
		free(time);
}

long	get_timestamp()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static t_philo *ft_create_pthreads(t_times *time)
{
	t_philo	*philos;
	int		i;

	philos = ft_calloc(sizeof(t_philo), time->number_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < time->number_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = get_timestamp();
		philos[i].time = *time;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
	return (philos);
}

static t_times *ft_manage_atoi_error(int error)
{
	if (error == 1)
		printf(B_RD_1"Invalid format: input is not a valid number.\n"RESET);
	if (error == 2)
		printf(B_RD_1"Overflow: number exceeds INT_MAX.\n"RESET);
	if (error == 3)
		printf(B_RD_1"Invalid number: Number cannot be negative.\n"RESET);
	if (error == 4)
		printf(B_RD_1"Syntax error: invalid characters.\n"RESET);
	if (error != 0)
		printf(B_GR_1"\nExample: ./philo 5 800 500 200 [6]\n\n"RESET);
	return (NULL);
}

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]
static t_times	*ft_create_time(char **argv, int argc)
{
	t_times	*time;
	int		error;

	time = ft_calloc(sizeof(t_times), 1);
	if (time == NULL)
		return (NULL);
	time->number_philos = ft_atoi_mod(argv[1], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	time->time_to_die = ft_atoi_mod(argv[2], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	time->time_to_eat = ft_atoi_mod(argv[3], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	time->time_to_sleep = ft_atoi_mod(argv[4], &error);
	if (error >= 1 && error <= 4)
		return(ft_manage_atoi_error(error));
	time->eat_limit = -1;
	if (argc != 6)
		return (time);
	time->eat_limit = ft_atoi_mod(argv[5], &error);
	if (error > 0 && error < 6)
		return(ft_manage_atoi_error(error));
	return (time);
}

static int	ft_return_printf(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int main(int argc, char **argv)
{
	t_philo	*philo;
	t_times	*time;

	if (argc < 5)
		return(ft_return_printf("Few arguments"));
	if (argc > 6)
		return(ft_return_printf("Too many arguments"));
	time = ft_create_time(argv, argc);
	if (time == NULL)
		return (1);
	print_times(time);
	philo = ft_create_pthreads(time);
	ft_free_philo(philo);
	ft_free_time(time);
	return (0);
}
