/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:37:44 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 04:57:10 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// El basico
/*void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Recibida la señal sigusr1!\n");
	else if (signum == SIGUSR2)
		printf("Recibida la señal sigusr2!\n");
}*/

//El que funciona a medias
/*void	signal_handler(int signum)
{
	static	char c;
	static	int bit;

	c = 0;
	bit = 0;
	if (signum == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
		bit = 0;
	}
}*/

//El que deberia de funcionar

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	(void)context;
	if (signum == SIGUSR2) // SIGUSR2 representa un '1'
		c |= (1 << (7 - bit));
	bit++;

	if (bit == 8) // Byte completo recibido
	{
		write(1, &c, 1);
		if (c == '\0') // Fin de mensaje
			write(1, "\n", 1);

		kill(info->si_pid, SIGUSR1);

		c = 0;
		bit = 0;
	}
}


void	binary_sigsur(char *msg, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (msg[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((msg[i] >> bit) & 1)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			usleep (100);
			bit--;
		}
		i++;
	}
}

int	main(void)
{
	struct sigaction sa;

	printf("Servidor en marcha. PID: %d\n", getpid());

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}

/*int	main(void)
{
	printf ("Servidor en marcha. PID: %d\n", getpid());
	signal (SIGUSR1, signal_handler);
	signal (SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}*/
