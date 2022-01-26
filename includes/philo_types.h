/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:00 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 01:44:52 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

# include <pthread.h>

typedef struct s_fork {
	int	id;
}	t_fork;

typedef struct s_var {
	struct s_time {
		int	die;
		int	eat;
		int	sleep;
	}			time;
	int			count;
	pthread_t	*philos;
	t_fork		*forks;
	int			must_eat;
}	t_var;

#endif
