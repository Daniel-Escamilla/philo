/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:43:31 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 12:03:48 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = -1;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (++i < dstsize - 1 && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (src_len);
}

static char	*ft_min(void)
{
	char	*arr;

	arr = (char *)ft_calloc(12, 1);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, "-2147483648", 12);
	return (arr);
}

static char	*ft_ifzero(void)
{
	char	*arr;

	arr = (char *)ft_calloc(2, 1);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, "0", 2);
	return (arr);
}

static char	*ft_memory(int len, int sign, long n)
{
	char	*arr;
	char	*ptr;

	arr = (char *)ft_calloc((size_t)len + 1, 1);
	if (arr == NULL)
		return (NULL);
	ptr = arr + len;
	*ptr-- = '\0';
	while (n > 0)
	{
		*ptr-- = (char)(n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*ptr = '-';
	ptr++;
	return (arr);
}

char	*ft_itoa(long n)
{
	int		sign;
	int		len;
	long	temp;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		len++;
		if (n == -2147483648)
			return (ft_min());
	}
	if (n == 0)
		return (ft_ifzero());
	temp = n;
	while (temp++ > 0)
	{
		temp /= 10;
		len++;
	}
	return (ft_memory(len, sign, n));
}
