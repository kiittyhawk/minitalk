/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:04 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/11 16:02:20 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	serv_sighandler(int signum, siginfo_t *info, void *contex)
{
	static int	received;

	(void)contex;
	(void)info;
	if (!received)
		received = 0;
	if (signum == SIGUSR1)
	{
		ft_putstr_fd("DONE\nReceived: ", 1);
		ft_putnbr_fd(received, 1);
		write(1, "\n", 1);
		received = 0;
	}
	if (signum == SIGUSR2)
		received += 8;
}

static void	send_byte(int c, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((c >> j) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Invalid PID\n", 12);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Invalid PID\n", 12);
				exit(0);
			}
		}
		j--;
		usleep(1000);
	}
}

static void	sendmsg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(msg[i], pid);
		i++;
	}
	send_byte('\0', pid);
}

static int	is_valid(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
		return (0);
	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig;

	g_sgsay.index = 0;
	g_sgsay.chr = 0;
	g_sgsay.bit = 0;
	g_sgsay.received = 0;
	if (!is_valid(argc, argv))
	{
		write(1, "Invalid format\nUse: ./client 'pid' 'msg'\n", 41);
		return (-1);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &serv_sighandler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sendmsg(ft_atoi(argv[1]), argv[2]);
}
