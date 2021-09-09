#include "../includes/minitalk.h"

void	send_byte(int pid, int	c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((c >> j) & 1)
			kill(pid, SIGUSR1);
		else if (!((c >> j) & 1))
			kill(pid, SIGUSR2);
		j--;
		usleep(100000);
	}
}

void	sendmsg(int pid, char *msg, int len)
{
	int		i;
	int		k;

	i = 0;
	k = 31;
	while (k >= 0)
	{
		if ((len >> k) & 1)
			kill(pid, SIGUSR1);
		else if (!((len >> k) & 1))
			kill(pid, SIGUSR2);
		k--;
		usleep(10000);
	}
	while (msg[i])
		send_byte(pid, msg[i++]);
	send_byte(pid, 0);
}

void	ft_sighandler(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Done\n", 5);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int	len;

	signal(SIGUSR2, &ft_sighandler);
	signal(SIGUSR1, &ft_sighandler);
	if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		sendmsg(ft_atoi(argv[1]), argv[2], len);
		pause();
	}
	else
		write(1, "Invalid format (./client 'pid' 'msg')", 37);
}
