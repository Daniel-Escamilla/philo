/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:08:52 by descamil          #+#    #+#             */
/*   Updated: 2025/03/19 09:45:58 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	ft_print_status(t_philo *philo, int msg_type)
{
	long				timestamp;
	static const char	*messages[] = {
		" is eating\n",
		" is sleeping\n",
		" has taken a fork\n",
		" is thinking\n",
		" died\n"
	};

	if (msg_type < 0 || msg_type > 5)
		return (1);
	timestamp = get_timestamp() - philo->time.start_time;
	pthread_mutex_lock(&philo->print_mutex);
	printf("%ld %d%s", timestamp, philo->id, messages[msg_type]);
	pthread_mutex_unlock(&philo->print_mutex);
	return (0);
}

void	ft_free_philo(t_philo *philos)
{
	int	i;

	if (!philos)
		return ;
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

static int	ft_return_printf(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_times	*time;
	int		ret;

	if (argc < 5)
		return (ft_return_printf("Few arguments"));
	if (argc > 6)
		return (ft_return_printf("Many arguments"));
	time = ft_create_time(argv, argc);
	if (!time)
		return (1);
	time->start_time = get_timestamp();
	ret = execute_threads(time, 0);
	return (ret);
}
