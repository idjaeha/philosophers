/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/28 17:10:23 by jayi             ###   ########.fr       */
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

static void	print_status(time_t now, int status, int idx)
{
	static char *message[] = {"has taken a fork", "is eating", ""\
							, "is sleeping", "", "is thinking", ""\
							, "died", "finish"};

	printf("%ld %d %s\n", now, idx, message[status]);
}



void	*act(void *data)
{
	t_var *var = ((t_philo *)data)->var;
	t_philo *philo  = ((t_philo *)data);
	time_t			now;

	now = get_mseconds();
	while (!var->is_end && get_gap(now) < philo->die)
	{
		if (philo->status == TAKEN_FORK)
			print_status(get_gap(now), philo->status++, philo->idx);
		else if (philo->status == START_EATING)
		{
			philo->act_end = var->time.eat + get_gap(now);
			philo->die = var->time.die + get_gap(now);
			print_status(get_gap(now), philo->status++, philo->idx);
		}
		else if (philo->status == EATING)
			philo->die = var->time.die + get_gap(now);
		else if (philo->status == START_SLEEPING)
		{
			philo->act_end = var->time.sleep + get_gap(now);
			print_status(get_gap(now), philo->status++, philo->idx);
		}
		else if (philo->status == START_THINKING)
		{
			print_status(get_gap(now), philo->status, philo->idx);
			philo->status = 0;
		}
		if (philo->act_end <= get_gap(now))
			philo->status++;
		now = get_mseconds();
	}
	print_status(now, 7, philo->idx);
	var->is_end = 1;
	return (NULL);
}