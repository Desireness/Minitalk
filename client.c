/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:37:56 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 02:11:10 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	//int server_pid;

	//server_pid = ft_atoi(av[1]);
	if (ac != 3)
	{
		printf("Uso: %s <PID> <1 o 2>\n", av[0]);
		return (1);
	}

	int server_pid = ft_atoi(av[1]);
	int signal_type = ft_atoi(av[2]);

	if (signal_type == 1)
		kill(pid, SIGUSR1);
	else if (signal_type == 2)
		kill(pid, SIGUSR2);
	else
	{
		printf("Debes ingresar 1 o 2 para la señal \n");
		return (1);
	}
	printf("Señal enviada a %d\n", pid);
	return (0);
}
