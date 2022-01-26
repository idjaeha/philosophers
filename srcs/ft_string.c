/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:14:17 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 01:53:08 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strchr(const char *str, int ch, char **ret)
{
	unsigned char	symbol;
	char			*cur_str;

	cur_str = (char *)str;
	symbol = ch;
	while (TRUE)
	{
		if (*cur_str == symbol)
		{
			*ret = cur_str;
			return (cur_str);
		}
		if (*cur_str == '\0')
		{
			*ret = NULL;
			return (NULL);
		}
		++cur_str;
	}
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t		count;
	char		*new_str;
	const char	*cur_str;

	cur_str = str;
	if (start <= ft_strlen(cur_str))
	{
		count = ft_strlen(cur_str) - start;
		if (count > len)
			count = len;
	}
	else
	{
		count = 0;
	}
	new_str = ft_calloc(count + 1, sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, cur_str + start, count + 1);
	return (new_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*cur_src;
	char		*cur_dst;

	cur_src = src;
	cur_dst = dst;
	if (dstsize != 0)
	{
		while (--dstsize && *cur_src != '\0')
		{
			*cur_dst = *cur_src;
			++cur_dst;
			++cur_src;
		}
		*cur_dst = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	const char	*cur_str;

	cur_str = str;
	while (*cur_str != '\0')
	{
		++cur_str;
	}
	return (cur_str - str);
}