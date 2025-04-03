/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:37:44 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 01:55:10 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Recibida la señal sigusr1!\n");
	else if (signum == SIGUSR2)
		printf("Recibida la señal sigusr2!\n");

}

int main(void)
{
	printf("Servidor en marcha. PID: %d\n" ,getpid());

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while(1)
		pause();

	return (0);
}

