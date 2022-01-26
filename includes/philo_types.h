/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:31:00 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 20:30:18 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPES_H
# define PHILO_TYPES_H

typedef struct s_var {
	struct s_time {
		int	die;
		int	eat;
		int	sleep;
	}	time;
	int	philo_count;
	struct s_philo {
		int	life;
		int	status;
	}	*philos;
	int	must_eat;
}	t_var;

#endif
