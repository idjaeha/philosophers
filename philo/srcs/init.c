/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:19:43 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 22:53:43 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_arg(char *str, int value, int doCheck)
{
	if (doCheck == FALSE)
		return (SUCCESS);
	if (value < 0)
	{
		ft_putstr_fd("인자는 음수일 수 없습니다.\n", 2);
		return (FAIL);
	}
	while (*str != '\0')
	{
		if (('0' <= *str && *str <= '9')
			|| *str == ' ' || *str == '+' || *str == '-')
			str++;
		else
		{
			ft_putstr_fd("인자는 숫자만 가능합니다.\n", 2);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

static void	init_philos(t_var *var)
{
	int		idx;
	t_philo	*philo;

	idx = -1;
	while (++idx < var->count)
	{
		philo = &var->philos[idx];
		philo->idx = idx;
		philo->var = var;
		philo->time_die = var->time.die;
		philo->act_end = 0;
		philo->left = &philo->fork;
		philo->right = &var->philos[(idx + 1) % var->count].fork;
		pthread_mutex_init(&philo->fork, NULL);
		pthread_mutex_init(&philo->eating, NULL);
	}
}

static int	init_var(t_var *var)
{
	var->is_end = 0;
	var->philos = ft_calloc(sizeof(t_philo), var->count);
	if (var->philos == NULL)
	{
		ft_putstr_fd("malloc에 실패했습니다.\n", 2);
		return (FAIL);
	}
	pthread_mutex_init(&var->print, NULL);
	print_message(NULL, 0, &var->print, FALSE);
	init_philos(var);
	return (SUCCESS);
}

int	init(t_var *var, int argc, char *argv[])
{
	var->count = ft_atoi(argv[1]);
	var->time.die = ft_atoi(argv[2]);
	var->time.eat = ft_atoi(argv[3]);
	var->time.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		var->must_eat = ft_atoi(argv[5]);
	else
		var->must_eat = -1;
	if (check_arg(argv[1], var->count, TRUE)
		&& check_arg(argv[2], var->time.die, TRUE)
		&& check_arg(argv[3], var->time.eat, TRUE)
		&& check_arg(argv[4], var->time.sleep, TRUE)
		&& check_arg(argv[5], var->must_eat, argc == 6))
		return (init_var(var));
	return (FAIL);
}
