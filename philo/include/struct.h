/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:13:36 by descamil          #+#    #+#             */
/*   Updated: 2025/03/12 15:15:10 by descamil         ###   ########.fr       */
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
	t_times		time;
}				t_philo;

#endif