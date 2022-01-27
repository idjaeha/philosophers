/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:00 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 14:27:30 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

# include <pthread.h>

typedef struct s_fork	t_fork;
typedef struct s_var 	t_var;
typedef struct s_arg 	t_arg;

struct s_fork {
	int	id;
};

struct s_var {
	struct s_time {
		int	die;
		int	eat;
		int	sleep;
	}					time;
	int					count;
	int					*status;
	int					*forks;
	int					must_eat;
	t_arg				*args;
	pthread_t			*philos;
	pthread_mutex_t		fork_lock;
};

struct s_arg {
	int		idx;
	t_var	*philo;
};

#endif
