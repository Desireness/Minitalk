/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:37:56 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 05:03:45 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ack_handler(int signum)
{
    (void)signum;
}

void	send_char(int pid, unsigned char c)
{
	int bit = 7;

	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2); // Enviar '1'
		else
			kill(pid, SIGUSR1); // Enviar '0'
		
		// ✅ Esperar confirmación del servidor antes de enviar el siguiente bit
		usleep(3000);
		bit--;
	}
}




int main(int ac, char **av)
{
	int		server_pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		printf("Uso: %s <PID> <mensaje>\n", av[0]);
		return (1);
	}
	server_pid = atoi(av[1]);
	message = av[2];

	signal(SIGUSR1, ack_handler); // ✅ Configurar el manejador de señal

	// Enviar el mensaje carácter por carácter
	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}

	send_char(server_pid, '\n');  // Enviar '\n' para separar mensajes
	send_char(server_pid, '\0');  // Enviar '\0' para indicar fin de transmisión

	printf("Mensaje enviado a %d\n", server_pid);
	return (0);
}
/*int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		printf("Uso: %s <PID> <mensaje>\n", av[0]);
		return (1);
	}

	server_pid = atoi(av[1]);
	message = av[2];

	// Configurar el manejador de señal para ACK
	signal(SIGUSR1, ack_handler);

	// Enviar el mensaje carácter por carácter
	i = 0;
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}

	send_char(server_pid, '\n');  // Enviar '\n' para separar mensajes
	send_char(server_pid, '\0');  // Enviar '\0' para indicar fin de transmisión

	printf("Mensaje enviado a %d\n", server_pid);
	return (0);
}*/

/*int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("Uso: %s <PID> <mensaje>\n", av[0]);
        return (1);
    }

    int server_pid = ft_atoi(av[1]);
    char *message = av[2];  // El mensaje a enviar
    int i = 0;

    // Para cada carácter del mensaje
    while (message[i] != '\0')
    {
        // Convertir el carácter a binario y enviarlo bit por bit
        unsigned char c = message[i];
        for (int bit = 7; bit >= 0; bit--)  // Iteramos sobre los bits de cada carácter (de izquierda a derecha)
        {
            if (c & (1 << bit))  // Si el bit es 1
                kill(server_pid, SIGUSR2);  // Enviar SIGUSR2
            else  // Si el bit es 0
                kill(server_pid, SIGUSR1);  // Enviar SIGUSR1

            usleep(100);  // Espera un pequeño tiempo entre señales para evitar problemas
        }
        i++;
    }

    printf("Mensaje enviado a %d\n", server_pid);
    return (0);
}*/


//Main antiguo, solo se comprueban las señales
/*int main(int ac, char **av)
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
		kill(server_pid, SIGUSR1);
	else if (signal_type == 2)
		kill(server_pid, SIGUSR2);
	else
	{
		printf("Debes ingresar 1 o 2 para la señal \n");
		return (1);
	}
	printf("Señal enviada a %d\n", server_pid);
	return (0);
}*/
