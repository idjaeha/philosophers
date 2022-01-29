/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:19:43 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 04:08:02 by jayi             ###   ########.fr       */
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

static void	init_philos(t_var *var)
{
	int	idx;

	idx = -1;
	while (++idx < var->count)
	{
		var->philos[idx].idx = idx;
		var->philos[idx].var = var;
		var->philos[idx].die = var->time.die;
		var->philos[idx].status = TAKEN_FORK;
		var->philos[idx].act_end = 0;
		var->philos[idx].left = &var->philos[idx].fork;
		var->philos[idx].right = &var->philos[(idx + 1) % var->count].fork;
		pthread_mutex_init(&var->philos[idx].fork, NULL);
		pthread_mutex_init(&var->philos[idx].eat_or_die, NULL);
		pthread_create(&var->philos[idx].act, NULL, act, &var->philos[idx]);
		pthread_create(&var->philos[idx].check_die, NULL, check_die, &var->philos[idx]);
	}
}

static void	init_var(t_var *var)
{
	var->is_end = 0;
	var->philos = ft_calloc(sizeof(t_philo), var->count);
	if (var->philos == NULL)
		philo_error("malloc에 실패했습니다.", 0);
	init_philos(var);
	if (var->must_eat != -1)
		pthread_create(&var->check_must_eat, NULL, check_must_eat, var);
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
	init_var(var);
}
