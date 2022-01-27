/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/28 06:38:04 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

/*
	밥 -> 잠 -> 생각
	1. 집으려고할때 뮤텍스를 건다.
		1. 
	2. 
*/

static void	print_status(int status, int idx)
{
	static char *message[] = {"has taken a fork", "is eating", ""\
							, "is sleeping", "", "is thinking", ""\
							, "died", "finish"};

	printf("%ld %d %s\n", get_mseconds(), idx, message[status]);
}

void	*act(void *data)
{
	t_var *var = ((t_philo *)data)->var;
	t_philo *philo  = ((t_philo *)data);
	int				idx = ((t_philo *)data)->idx;
	time_t			now;

	now = get_mseconds();
	while (!var->is_end && now < var->philos[idx].die)
	{
		if (philo->status[idx] == TAKEN_FORK)
		{
			print_status(philo->status[idx], idx);
			philo->status[idx]++;
		}
		else if (philo->status[idx] == START_EATING)
		{
			var->philos[idx].act_end = var->time.eat + now;
			var->philos[idx].die = var->time.die + now;
			print_status(philo->status[idx], idx);
			philo->status[idx]++;
		}
		else if (philo->status[idx] == START_SLEEPING)
		{
			var->philos[idx].act_end = var->time.sleep + now;
			print_status(philo->status[idx], idx);
			philo->status[idx]++;
		}
		else if (philo->status[idx] == START_THINKING)
		{
			print_status(philo->status[idx], idx);
			philo->status[idx] = 0;
		}
		else if (var->philos[idx].act_end <= now)
			philo->status[idx]++;
		now = get_mseconds();
	}
	print_status(7, idx);
	var->is_end = 1;
	return NULL;
}