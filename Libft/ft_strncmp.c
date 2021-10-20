/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:14:45 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:14:46 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- && (str1[i] || str2[i]))
	{
		if (*str1++ != *str2++)
			return ((unsigned char)*--str1 - (unsigned char)*--str2);
	}
	return (0);
}
