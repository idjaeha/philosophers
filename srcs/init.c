/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:19:43 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 20:35:11 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_arg(char *str, int value, int doCheck)
{
	if (doCheck == FALSE)
		return ;
	if (value < 0)
		philo_error("인자는 음수일 수 없습니다.", 1);
	while (*str != '\0')
	{
		if (('0' <= *str && *str <= '9') || *str == ' ' || *str == '+' || *str == '-')
			str++;
		else
			philo_error("인자는 숫자만 가능합니다.", 1);
	}
}

void	init_argv(t_var *philo, int argc, char *argv[])
{
	philo->philo_count = ft_atoi(argv[1]);
	philo->time.die = ft_atoi(argv[2]);
	philo->time.eat = ft_atoi(argv[3]);
	philo->time.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]);
	check_arg(argv[1], philo->philo_count, TRUE);
	check_arg(argv[2], philo->time.die, TRUE);
	check_arg(argv[3], philo->time.eat, TRUE);
	check_arg(argv[4], philo->time.sleep, TRUE);
	check_arg(argv[5], philo->must_eat, argc == 6);
}