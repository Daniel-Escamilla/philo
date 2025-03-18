/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:12:19 by descamil          #+#    #+#             */
/*   Updated: 2025/03/18 12:21:18 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define EATING 0
# define SLEEPING 1
# define FORK 2
# define THINKING 3
# define MUST_EAT 4
# define DIED 5

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

# include "struct.h"
# include "main.h"
# include "utils.h"
# include "colors.h"
# include "execution.h"

#endif