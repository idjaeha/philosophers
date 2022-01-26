/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:32:03 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 21:16:25 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoi_minus(const char *str)
{
	unsigned long long	result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483648)
		{
			philo_error("negative overflow error", 1);
		}
		if (result > ABS_LLONG_MIN)
		{
			return ((int)ABS_LLONG_MIN);
		}
		++str;
	}
	return (result * -1);
}

static int	ft_atoi_plus(const char *str)
{
	unsigned long long	result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > MAX_INT)
		{
			philo_error("positive overflow error", 1);
		}
		if (result > ABS_LLONG_MAX)
		{
			return ((int)ABS_LLONG_MAX);
		}
		++str;
	}
	return (result);
}

static int	ft_isspace(char symbol)
{
	if (symbol == ' ' || symbol == '\t' || symbol == '\n'
		|| symbol == '\v' || symbol == '\f' || symbol == '\r')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	const char	*cursor_str;

	cursor_str = str;
	while (ft_isspace(*cursor_str))
	{
		++cursor_str;
	}
	if (*cursor_str == '-')
	{
		return (ft_atoi_minus(++cursor_str));
	}
	else if (*cursor_str == '+')
	{
		return (ft_atoi_plus(++cursor_str));
	}
	else
	{
		return (ft_atoi_plus(cursor_str));
	}
}
