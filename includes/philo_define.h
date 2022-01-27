/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:01 by jayi              #+#    #+#             */
/*   Updated: 2022/01/28 06:12:04 by jayi             ###   ########.fr       */
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

# define TAKEN_FORK 0
# define START_EATING 1
# define EATING 2
# define START_SLEEPING 3
# define SLEEPING 4
# define START_THINKING 5
# define THINKING 6

# define STATUS_DIED 4
# define STATUS_END 5

#endif
