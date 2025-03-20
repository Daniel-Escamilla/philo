/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:40:04 by descamil          #+#    #+#             */
/*   Updated: 2025/03/20 11:05:34 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	char	*ptr_chr;
	void	*ptr;
	size_t	i;

	if ((nmemb == SIZE_MAX) || (size == SIZE_MAX))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	ptr_chr = (char *)ptr;
	while (i < total_size)
		ptr_chr[i++] = '\0';
	return (ptr);
}
