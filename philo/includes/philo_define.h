/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:01 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 21:23:39 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINE_H
# define PHILO_DEFINE_H

# define ABS_LLONG_MAX 	9223372036854775807ULL
# define ABS_LLONG_MIN 	9223372036854775808ULL
# define MAX_INT 0x7FFFFFFF
# define MIN_INT 0xFFFFFFFF
# define TRUE 1
# define FALSE 0
# define DEBUG 1
# define MAX_COUNT 100

# define STATUS_DIED 4
# define STATUS_END 5

# define MSG_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "died"

#endif
