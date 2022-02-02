/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:09:13 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 22:25:21 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_thread(t_var *var)
{
	int	idx;

	idx = -1;
	while (++idx < var->count)
	{
		if (var->philos[idx].act == 0)
		{
			ft_putstr_fd("스레드가 생성되지 않았습니다.\n", 2);
			return (FAIL);
		}
		if (var->philos[idx].check_die == 0)
		{
			ft_putstr_fd("스레드가 생성되지 않았습니다.\n", 2);
			return (FAIL);
		}
	}
	if (var->must_eat != -1 && var->check_must_eat == 0)
	{
		ft_putstr_fd("스레드가 생성되지 않았습니다.\n", 2);
		return (FAIL);
	}
	return (SUCCESS);
}

int	start(t_var *var)
{
	int	idx;

	idx = -1;
	get_mseconds();
	while (++idx < var->count)
		pthread_create(&var->philos[idx].act, NULL, act, &var->philos[idx]);
	while (--idx >= 0)
		pthread_create(&var->philos[idx].check_die \
		, NULL, check_die, &var->philos[idx]);
	if (var->must_eat != -1)
		pthread_create(&var->check_must_eat, NULL, check_must_eat, var);
	return (check_thread(var));
}
