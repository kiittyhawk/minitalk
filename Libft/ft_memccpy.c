/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:13:09 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:13:10 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char				*str1;
	const unsigned char			*str2;
	unsigned char				sym;
	size_t						i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char const *)src;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == sym)
		{
			i++;
			return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
