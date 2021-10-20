/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:13:13 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:13:14 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		sym;
	size_t				i;

	str = (const unsigned char *)s;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == sym)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
