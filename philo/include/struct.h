/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:13:36 by descamil          #+#    #+#             */
/*   Updated: 2025/03/19 09:27:36 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../philo.h"

typedef struct s_times
{
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_limit;
	long			start_time;
	pthread_mutex_t	turn_mutex;
}				t_times;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_times	time;
}					t_philo;

#endif
