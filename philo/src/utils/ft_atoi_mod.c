/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:21:42 by descamil          #+#    #+#             */
/*   Updated: 2025/03/12 15:32:53 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

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
			*error = 2;
		else if (sign == -1 && (result > (INT_MAX / 10)
				|| (result == (INT_MAX / 10) && digit > 8)))
			*error = 3;
		if (*error != 0)
			return (0);
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
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (handle_sign(str, &i, &sign) && (str[i] == '-'
			|| str[i] == '+' || (str[i] < '0' || str[i] > '9')))
	{
		*error = 1;
		return (0);
	}
	result = calculate_result(str, &i, error, sign);
	if (str[i] != '\0')
	{
		*error = 4;
		return (0);
	}
	return (result * sign);
}
