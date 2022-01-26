/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:54:39 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 01:55:12 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
