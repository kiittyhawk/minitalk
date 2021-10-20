/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:15:24 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 15:15:25 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_sgsay
{
	int		chr;
	int		index;
	int		bit;
	int		received;
}				t_sgsay;

t_sgsay	g_sgsay;

#endif
