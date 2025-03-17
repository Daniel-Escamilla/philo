/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:52:09 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 13:17:29 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	print_times(t_times *times)
{
	printf(B_GR_0 "Philosophers: " RESET "%d\n\n", times->number_philos);
	printf(B_RD_0 "Time to die: " RESET "%d ms\n\n", times->time_to_die);
	printf(B_OR_0 "Time to eat: " RESET "%d ms\n\n", times->time_to_eat);
	printf(B_BL_0 "Time to sleep: " RESET "%d ms\n\n", times->time_to_sleep);
	if (times->eat_limit != -1)
		printf(B_YE_0 "Eat limit: " RESET "%d times\n\n", times->eat_limit);
	else
		printf(B_YE_0 "Eat limit: " RESET B_RD_0 "Without limit\n\n" RESET);
}
