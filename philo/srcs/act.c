/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/02/03 00:47:43 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// t_philo *을 인자로 받고
// t_philo *을 인자로 받는 함수 포인터를 반환하는 함수
// (*(t_philo *philo))(t_philo *)

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_message(MSG_FORK, philo->idx, NULL, philo->var);
	pthread_mutex_lock(philo->right);
	print_message(MSG_FORK, philo->idx, NULL, philo->var);
}

static void	eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&philo->eating);
	{
		now = get_mseconds();
		philo->count_eat++;
		philo->time_end = philo->var->time.eat + now;
		philo->time_die = philo->var->time.die + now;
		print_message(MSG_EATING, philo->idx, NULL, philo->var);
	}
	pthread_mutex_unlock(&philo->eating);
	idle(now, philo->var->time.eat);
}

static void	sleeping(t_philo *philo)
{
	time_t	now;

	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	{
		now = get_mseconds();
		philo->time_end = philo->var->time.sleep + now;
		print_message(MSG_SLEEPING, philo->idx, NULL, philo->var);
		idle(now, philo->var->time.sleep);
	}
}

static void	thinking(t_philo *philo)
{
	print_message(MSG_THINKING, philo->idx, NULL, philo->var);
}

void	*act(void *data)
{
	int				current_idx;
	t_philo *const	philo = data;
	static	void	(*current_act[4])(t_philo *) = \
	{taken_fork, eating, sleeping, thinking};

	current_idx = 0;
	if (philo->idx & 1)
		usleep(philo->var->time.eat * 100);
	while (philo->var->is_end == 0)
		current_act[current_idx++ % 4](philo);
	return (NULL);
}
