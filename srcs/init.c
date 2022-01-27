/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:19:43 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 17:55:03 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_arg(char *str, int value, int doCheck)
{
	if (doCheck == FALSE)
		return ;
	if (value < 0)
		philo_error("인자는 음수일 수 없습니다.", 0);
	while (*str != '\0')
	{
		if (('0' <= *str && *str <= '9')
			|| *str == ' ' || *str == '+' || *str == '-')
			str++;
		else
			philo_error("인자는 숫자만 가능합니다.", 0);
	}
}

static void	init_philo(t_var *var)
{
	int	idx;

	idx = -1;
	var->forks = malloc(sizeof(int) * var->count);
	var->status = ft_calloc(sizeof(int), var->count);
	var->philos = ft_calloc(sizeof(t_philo), var->count);
	var->philo_threads = malloc(sizeof(pthread_t) * var->count);
	pthread_mutex_init(&var->fork_lock, NULL);
	while (++idx < var->count)
	{
		var->philos[idx].idx = idx;
		var->philos[idx].var = var;
		var->philos[idx].end = var->time.die;
		var->philos[idx].die = var->time.die;
		var->philos[idx].status = var->status;
		pthread_create(&var->philo_threads[idx], NULL, act, &var->philos[idx]);
	}
	while (--idx > 0)
		pthread_join(var->philo_threads[idx], NULL);
}

void	init(t_var *var, int argc, char *argv[])
{
	var->count = ft_atoi(argv[1]);
	var->time.die = ft_atoi(argv[2]);
	var->time.eat = ft_atoi(argv[3]);
	var->time.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		var->must_eat = ft_atoi(argv[5]);
	else
		var->must_eat = -1;
	check_arg(argv[1], var->count, TRUE);
	check_arg(argv[2], var->time.die, TRUE);
	check_arg(argv[3], var->time.eat, TRUE);
	check_arg(argv[4], var->time.sleep, TRUE);
	check_arg(argv[5], var->must_eat, argc == 6);
	init_philo(var);
}
