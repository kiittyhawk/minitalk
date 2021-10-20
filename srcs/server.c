/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:01:59 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 16:02:49 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	writer(struct __siginfo *info)
{
	if (g_sgsay.chr != 0)
		write(1, &g_sgsay.chr, 1);
	else
	{
		kill(info->si_pid, SIGUSR1);
		write(1, "\n", 1);
	}
}

static void	ft_sighandler(int signum, struct __siginfo *info, void *context)
{
	(void) info;
	(void) context;
	if (g_sgsay.bit == 0)
		g_sgsay.bit = 128;
	if (signum == SIGUSR1)
	{
		g_sgsay.chr += g_sgsay.bit;
		g_sgsay.bit /= 2;
		g_sgsay.index++;
	}
	else
	{
		g_sgsay.bit /= 2;
		g_sgsay.index++;
	}
	if (g_sgsay.index == 8)
	{
		kill(info->si_pid, SIGUSR2);
		writer(info);
		g_sgsay.bit = 128;
		g_sgsay.chr = 0;
		g_sgsay.index = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sighandler;
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		pause();
}
