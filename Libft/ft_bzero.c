/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:12:31 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:12:32 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	len;

	str = (unsigned char *)s;
	len = (unsigned int)n;
	while (len != 0)
	{
		*str++ = '\0';
		len--;
	}
	return (str);
}
