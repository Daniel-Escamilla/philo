/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:12:19 by descamil          #+#    #+#             */
/*   Updated: 2025/03/20 11:04:25 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘INCLUDE〙
# define EATING 0
# define SLEEPING 1
# define FORK 2
# define THINKING 3
# define DIED 4

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