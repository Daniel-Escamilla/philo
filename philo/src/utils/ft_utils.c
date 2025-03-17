/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:51:47 by descamil          #+#    #+#             */
/*   Updated: 2025/03/17 12:20:25 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	n = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ptr = malloc(n + 1);
	if (ptr == NULL)
		return (NULL);
	while ((char)s1[++i] != '\0')
		ptr[i] = (char)s1[i];
	while ((char)s2[j] != '\0')
		ptr[i++] = (char)s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_exit_perror(char *error, int status)
{
	perror(error);
	exit(status);
}
