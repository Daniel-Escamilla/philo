/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:46:06 by descamil          #+#    #+#             */
/*   Updated: 2025/03/18 10:48:23 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

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

t_times	*ft_create_time(char **argv, int argc)
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
