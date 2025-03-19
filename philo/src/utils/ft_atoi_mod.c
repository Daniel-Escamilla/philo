/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:42 by descamil          #+#    #+#             */
/*   Updated: 2025/03/19 09:41:06 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	ft_exit_error(int *error, int status)
{
	*error = status;
	return (0);
}

static int	handle_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	else
		return (0);
	return (1);
}

static int	calculate_result(char *str, int *i, int *error, int sign)
{
	int	result;
	int	digit;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		digit = str[*i] - '0';
		if (sign == 1 && (result > (INT_MAX / 10)
				|| (result == (INT_MAX / 10) && digit > 7)))
			return (ft_exit_error(error, 2));
		if (sign == -1)
			return (ft_exit_error(error, 3));
		result = result * 10 + digit;
		(*i)++;
	}
	return (result);
}

int	ft_atoi_mod(char *str, int *error)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	*error = 0;
	if (str[0] == '\0')
		return (ft_exit_error(error, 5));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (handle_sign(str, &i, &sign) && (str[i] == '-'
			|| str[i] == '+' || (str[i] < '0' && str[i] > '9')))
		return (ft_exit_error(error, 1));
	result = calculate_result(str, &i, error, sign);
	if (str[i] != '\0' && (*error != 3 && *error != 2))
		return (ft_exit_error(error, 4));
	return (result * sign);
}
