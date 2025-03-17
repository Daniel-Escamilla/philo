/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:13:36 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 13:03:17 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../philo.h"

typedef struct s_times
{
	int			number_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_limit;
}				t_times;

typedef struct s_philo
{
    int				id;
    long			last_meal_time;
    pthread_mutex_t	meal_mutex;
    struct s_times	time;
} t_philo;


#endif
