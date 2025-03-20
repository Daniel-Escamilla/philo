/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:10:17 by descamil          #+#    #+#             */
/*   Updated: 2025/03/20 11:04:38 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘MAIN〙
# include "../philo.h"

// ft_main.c
int		main(int argc, char **argv);
void	ft_free_time(t_times *time);
void	ft_free_philo(t_philo *philos);
int		ft_print_status(t_philo *philo, int msg_type);

// ft_initialice.c
t_times	*ft_create_time(char **argv, int argc);

#endif