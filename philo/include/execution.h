/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:09:21 by descamil          #+#    #+#             */
/*   Updated: 2025/03/20 11:04:08 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘PHILO〙
# include "../philo.h"

//ft_execution.c
void		*monitor_routine(void *arg);
void		*philosopher_routine(void *arg);
pthread_t	*ft_create_threads(t_philo *philos);
int			execute_threads(t_times *time, int i);
t_philo		*ft_init_threads(t_times *time, int i);

#endif