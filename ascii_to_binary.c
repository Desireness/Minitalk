/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:32:08 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 04:21:50 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void asciibinary(unsigned char c, char *binary, unsigned char mask, int i) {
    if (i >= 8) {
        binary[8] = '\0';
        return;
    }
    if (c & mask) {
        binary[i] = '1';
    } else {
        binary[i] = '0';
    }
    asciibinary(c, binary, mask / 2, i + 1);
}




void string_to_binary_recursive(const char *str, char *result) {
    if (*str == '\0') {
        *result = '\0';
        return;
    }

    char binary[9];
    asciibinary(*str, binary, 128, 0); // Usamos la versión recursiva
    memcpy(result, binary, 8);
    result += 8;

    if (*(str + 1) != '\0') {
        *result = ' ';
        result++;
    }

    string_to_binary_recursive(str + 1, result); // Siguiente carácter
}

//main por argumentos
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Uso: %s <texto>\n", argv[0]);
        return 1;
    }

    char resultado[strlen(argv[1]) * 9 + 1];
    
    string_to_binary_recursive(argv[1], resultado);
    printf("%s\n", resultado);

    return 0;
}


//main para un string a binario (string definido en el main)

/*int main() {
    // 1. Conversión de un carácter
    char binary[9];
    ascii_to_binary_recursive('B', binary, 128, 0);
    printf("'B' en binario: %s\n", binary);

    // 2. Conversión de un string
    char texto[] = "RAUL";
    char resultado[sizeof(texto) * 9]; // 8 bits + espacio por carácter
    string_to_binary_recursive(texto, resultado);
    printf("'%s' en binario:\n%s\n", texto, resultado);

    return 0;
}*/


//char to binary:
/*int main()
{
	char input;
	printf("Ingrese un caracter: ");
	scanf("%c", &input);

	char binary[9];
	ascii_to_binary(input, binary);

	printf("'%c' (ASCII %d) en binario: %s\n", input, input, binary);
	return 0;
}*/
