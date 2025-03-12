/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:08:52 by descamil          #+#    #+#             */
/*   Updated: 2025/03/12 16:06:54 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static t_philo *ft_manage_atoi_error(int error)
{
	if (error == 1)
		printf("Invalid format: input is not a valid number.\n");
	if (error == 2)
		printf("Overflow: number exceeds INT_MAX.\n");
	if (error == 3)
		printf("Underflow: number is smaller than INT_MIN.\n");
	if (error == 4)
		printf("Syntax error: invalid characters after the number.\n");
	return (NULL);
}
// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]
static t_philo	*ft_create_struct(char **argv, int argc)
{
	t_philo	*philo;
	int		error;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (philo == NULL)
		return (NULL);		
	philo->time.number_philos = ft_atoi_mod(argv[1], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	philo->time.time_to_die = ft_atoi_mod(argv[2], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	philo->time.time_to_eat = ft_atoi_mod(argv[3], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	philo->time.time_to_sleep = ft_atoi_mod(argv[4], &error);
	if (error >= 1 && error <= 4)
		return(ft_manage_atoi_error(error));
	philo->time.eat_limit = -1;
	if (argc != 6)
		return (philo);
	philo->time.eat_limit = ft_atoi_mod(argv[5], &error);
	if (error > 0 && error < 5)
		return(ft_manage_atoi_error(error));
	return (philo);
}

static int	ft_return_printf(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5)
		return(ft_return_printf("Few arguments"));
	if (argc > 6)
		return(ft_return_printf("Too many arguments"));
	philo = ft_create_struct(argv, argc);
	if (philo == NULL)
		return (1);
	ft_print_philo(philo);
	free(philo);
	return (0);
}