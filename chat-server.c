/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat-server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:41:13 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 01:36:28 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// FUNCIONES Y COSAS RELACIONADAS CON EL CLIENTE
//creamos un socket
int main()
{
	int conexion;
	if((conexion = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf(stderr, "Error al crear el socket\n");
		return 1;
	}
}


//resolvemos el dominio con gethostbyname
struct	hostent *servidor;
servidor = gethostbyname("google.com");
if(servidor == NULL)
{
	printf("La dirección Ip del host es errónea\n");
	return 1;
}

//nos conectamos con el host con connect

if(connect(conexion, (struct sockadrr *)&client, sizeof(cliente)) < 0)
{
	printf("Imposible conectar con el host\n");
	return 1;
}

//send o write

char buffer [200];
write(conexion, buffer, 200);
...
send(conexion, buffer, 200);

//read() o recv()

char buffer[200];
read(conexion, buffer, 200); //conexion es el socket
...
recv(conexion, buffer, 200);


//FUNCIONES Y COSAS RELACIONADAS CON EL SERVIDOR

//Usamos el socket(); que hemos definido antes	

//bind(); sirve para asignar un puerto

bind(conexion_servidor, (struct sockadrr *)&servidor, sizeof(servidor));

//listen(); -> sirve para poner a la escucha a un socket:

listen(conexion_servidor, 3);

//accept(); -> escucha y permite que algun cliente se conecte despues de connect();

int clilong = sizeof(cliente);
conexion_cliente = accept(conexion_socket, (struct sockadrr *)&cliente, &clilong);







