/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:13:30 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:13:31 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	s;
	size_t			i;

	str = (unsigned char *)b;
	s = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = s;
		i++;
	}
	return (str);
}
