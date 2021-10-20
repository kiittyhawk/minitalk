/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:13:23 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:13:24 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *str, size_t n)
{
	unsigned char				*str1;
	const unsigned char			*str2;
	size_t						i;

	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)str;
	i = 0;
	if (str1 == '\0' && str2 == '\0')
		return (0);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
