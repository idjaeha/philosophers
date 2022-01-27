/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 17:57:51 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

/*
	밥 -> 잠 -> 생각
	1. 집으려고할때 뮤텍스를 건다.
		1. 
	2. 
*/

static void	print_status(int status, int idx)
{
	static char *message[] = {"is thinking", "died", "is eating", "is sleeping", "finish", "has taken a fork"};

	printf("%ld %d %s\n", get_mseconds(), idx, message[status]);
}

void	*act(void *data)
{
	const t_var		*var = ((t_philo *)data)->var;
	const t_philo	*philo = ((t_philo *)data);
	int				idx = ((t_philo *)data)->idx;

	while (philo->status[idx] != STATUS_DIED && philo->status[idx] != STATUS_END)
	{
		if (philo->status[idx] != STATUS_EATING && get_mseconds() >= philo->die)
			philo->status[idx] = STATUS_DIED;
		if (var->must_eat != -1 && philo->eat >= var->must_eat)
			philo->status[idx] = STATUS_END;
		if (philo->status[idx] == STATUS_THINKING)
		{
			philo->status[idx] = STATUS_EATING;
			var->philos[idx].end = var->time.eat + get_mseconds();
			print_status(5, idx);
		}
		else if (philo->status[idx] == STATUS_EATING & get_mseconds() >= philo->end)
		{
			philo->status[idx] = STATUS_SLEEPING;
			var->philos[idx].eat += 1;
			var->philos[idx].die = var->time.die + get_mseconds();
			var->philos[idx].end = var->time.sleep + get_mseconds();
		}
		else if (philo->status[idx] == STATUS_SLEEPING & get_mseconds() >= philo->end)
			philo->status[idx] = STATUS_THINKING;
		print_status(philo->status[idx], idx);
	}
	return NULL;
}