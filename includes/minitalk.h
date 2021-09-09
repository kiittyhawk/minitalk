#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_sgsay
{
	int		len;
	int		error;
	char	*str;
	int		chr;
	int		index;
	int		sig_num;
}				t_sgsay;

t_sgsay	g_sgsay;

void	send_message(int i);

#endif
