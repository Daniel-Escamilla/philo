/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:23:06 by descamil          #+#    #+#             */
/*   Updated: 2025/03/12 15:51:51 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

int		ft_atoi_mod(char *str, int *error);
void	ft_print_philo(t_philo *philo);
void	*ft_calloc(size_t nmemb, size_t size);

#endif