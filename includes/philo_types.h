/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:00 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 21:18:29 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

typedef struct s_fork {
	int	id;
}	t_fork;

typedef struct s_var {
	struct s_time {
		int	die;
		int	eat;
		int	sleep;
	}	time;
	int	count;
	struct s_philo {
		int	life;
		int	status;
	}	*philos;
	t_fork	*forks;
	int	must_eat;
}	t_var;

#endif
