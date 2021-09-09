#include "../includes/minitalk.h"

void	send_message(int i)
{
	if (i == 1)
		write(1, "The client is gone!", 19);
	if (i == 2)
		write(1, "Memory error", 12);
	exit(0);
}

void	stop_client(int client)
{
	int	i;

	g_sgsay.sig_num = 0;
	g_sgsay.chr = 0;
	g_sgsay.len = 0;
	g_sgsay.index = 0;
	ft_putstr(g_sgsay.str);
	free(g_sgsay.str);
	g_sgsay.str = NULL;
	write(1, "\n", 1);
	i = kill(client, SIGUSR2);
	if (i == -1)
		send_message(1);
}

void	ft_length(void)
{
	g_sgsay.len = (g_sgsay.len << 8) ^ g_sgsay.chr;
	if (g_sgsay.sig_num == 32)
	{
		g_sgsay.str = malloc(g_sgsay.len + 1 * sizeof(char));
		if (!g_sgsay.str)
			send_message(2);
		g_sgsay.len = 0;
	}
}

void	ft_sighandler(int signum, siginfo_t *sig, void *context)
{
	(void)context;
	g_sgsay.sig_num++;
	g_sgsay.chr = g_sgsay.chr << 1;
	if (signum == SIGUSR1)
		g_sgsay.chr = g_sgsay.chr ^ 1;
	if (g_sgsay.sig_num % 8 == 0)
	{
		if (g_sgsay.sig_num <= 32)
			ft_length();
		else
		{
			if (g_sgsay.str)
				g_sgsay.str[g_sgsay.index++] = g_sgsay.chr;
			else
				send_message(2);
			if (!g_sgsay.chr)
				stop_client(sig->si_pid);
		}
		g_sgsay.chr = 0;
	}
	g_sgsay.error = kill(sig->si_pid, SIGUSR1);
	if (g_sgsay.error == -1)
		stop_client(sig->si_pid);
}

int	main(void)
{
	struct sigaction	sig;

	g_sgsay.chr = 0;
	g_sgsay.len = 0;
	g_sgsay.index = 0;
	g_sgsay.sig_num = 0;
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
