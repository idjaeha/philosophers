/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/29 05:53:48 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	if (philo->var->is_end == 0)
		print_message(get_mseconds(), MSG_FORK, philo->idx);
	philo->status++;
}

static void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*act(void *data)
{
	t_var	*var;
	t_philo	*philo;

	var = ((t_philo *)data)->var;
	philo = (t_philo *)data;
	if ((philo->idx & 1) == 0)
		usleep(var->time.eat * 1000);
	while (var->is_end == 0)
	{
		if (philo->status == TAKEN_FORK)
			taken_fork(philo);
		else if (philo->status == START_EATING)
		{
			philo->eat++;
			philo->act_end = var->time.eat + get_mseconds();
			philo->die = var->time.die + get_mseconds();
			print_message(get_mseconds(), philo->status++, philo->idx);
		}
		else if (philo->status == START_SLEEPING)
		{
			release_fork(philo);
			philo->act_end = var->time.sleep + get_mseconds();
			print_message(get_mseconds(), philo->status++, philo->idx);
		}
		else if (philo->status == START_THINKING)
		{
			print_message(get_mseconds(), philo->status, philo->idx);
			philo->status = 0;
		}
		else if (philo->act_end <= get_mseconds())
			philo->status++;
	}
	release_fork(philo);
	return (NULL);
}
