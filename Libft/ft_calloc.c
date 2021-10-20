/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:12:35 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:12:36 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buff;

	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, nmemb * size);
	return (buff);
}
