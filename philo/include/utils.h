/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:23:06 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 13:18:16 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

// ft_atoi_mod.c
int		ft_atoi_mod(char *str, int *error);

// ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);

// ft_itoa.c
char	*ft_itoa(long n);

// ft_print_philo.c
void	print_times(t_times *times);

// ft_utils.c
int		ft_strlen(const char *str);
void	ft_exit_perror(char *error, int status);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
