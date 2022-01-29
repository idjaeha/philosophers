/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:46:44 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 03:00:36 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr_fd(char *str, int fd)
{
	char	*cur_str;

	cur_str = str;
	write(fd, cur_str, ft_strlen(cur_str));
}

static void	ft_recv_putnbr_fd(int n, int depth, int fd, int sign)
{
	char	ch_num;

	ch_num = '0';
	if (n == 0)
	{
		if (depth == 0)
		{
			write(fd, &ch_num, 1);
		}
		else if (sign == -1)
		{
			write(fd, "-", 1);
		}
		return ;
	}
	ft_recv_putnbr_fd(n / 10, depth + 1, fd, sign);
	ch_num += (n % 10) * sign;
	write(fd, &ch_num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	((n < 0) && (sign = -1)) || ((n >= 0) && (sign = 1));
	ft_recv_putnbr_fd(n, 0, fd, sign);
}

void	print_message(time_t now, int status, int idx)
{
	static char	*message[] = {"has taken a fork", "is eating", "", \
	"is sleeping", "has taken a left fork", "is thinking", \
	"has taken a right fork", "died", "finish"};

	printf("%ld\t%d\t%s\n", now, idx + 1, message[status]);
}
