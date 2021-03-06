/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:46:44 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 23:57:26 by jayi             ###   ########.fr       */
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

void	print_message(
		char *message, int idx, pthread_mutex_t *print, t_var *var)
{
	static pthread_mutex_t	*m_print = NULL;

	if (print == NULL)
	{
		pthread_mutex_lock(m_print);
		if (var->is_end != FALSE)
		{
			pthread_mutex_unlock(m_print);
			return ;
		}
		printf("%ld\t%d\t%s\n", get_mseconds(), idx + 1, message);
		pthread_mutex_unlock(m_print);
	}
	else if (var->is_end == TRUE)
	{
		pthread_mutex_lock(m_print);
		printf("%ld\t%d\t%s\n", get_mseconds(), idx + 1, message);
	}
	else
	{
		m_print = print;
	}
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
