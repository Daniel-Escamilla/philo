/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:08:52 by descamil          #+#    #+#             */
/*   Updated: 2025/03/12 12:45:30 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static int	ft_return_printf(const char *str)
{
	printf("%s\n", str);
	return (1);
}

int main(int argc, char **argv)
{
	(void) argv;
	if (argc < 5)
		return(ft_return_printf("Few arguments"));
	if (argc > 6)
		return(ft_return_printf("To much arguments"));
}