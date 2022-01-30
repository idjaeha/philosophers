/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:46:44 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 21:04:00 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	ft_strlen(const char *str)
{
	const char	*cur_str;

	cur_str = str;
	while (*cur_str != '\0')
	{
		++cur_str;
	}
	return (cur_str - str);
}

void	ft_putstr_fd(char *str, int fd)
{
	char	*cur_str;

	cur_str = str;
	write(fd, cur_str, ft_strlen(cur_str));
}

void	print_message(time_t now, int status, int idx)
{
	static char	*message[] = {"has taken a fork", "is eating", "", \
	"is sleeping", "has taken a left fork", "is thinking", \
	"has taken a right fork", "died", "finish"};

	printf("%ld\t%d\t%s\n", now, idx + 1, message[status]);
}

void	*ft_memset(void *byte_str, int ch, size_t len)
{
	char	*idx_byte;
	char	*end_byte;

	idx_byte = byte_str;
	end_byte = byte_str + len;
	while (idx_byte != end_byte)
	{
		*idx_byte = ch;
		++idx_byte;
	}
	return (byte_str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_memory;
	int		len;

	len = count * size;
	new_memory = malloc(len);
	if (new_memory == NULL)
	{
		return (NULL);
	}
	return (ft_memset(new_memory, 0, len));
}
