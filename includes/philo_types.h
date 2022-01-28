/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:00 by jayi              #+#    #+#             */
/*   Updated: 2022/01/29 04:47:38 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

# include <pthread.h>

typedef struct s_fork	t_fork;
typedef struct s_var 	t_var;
typedef struct s_philo 	t_philo;

struct s_fork {
	int	id;
};

struct s_var {
	struct s_time {
		int	die;
		int	eat;
		int	sleep;
	}					time;
	int					is_end;
	int					count;
	int					must_eat;
	t_philo				*philos;
	pthread_t			*philo_threads;
	pthread_mutex_t		*forks;
};

struct s_philo {
	int				die;
	int				eat;
	int				idx;
	int				status;
	int				act_end;
	t_var			*var;
	time_t			create;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
};

#endif
