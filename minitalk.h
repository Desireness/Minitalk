/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:41:32 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/03 04:19:42 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define MINITALK_H

#include "libft.h"  // Si usas listas de la libft
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <sys/socket.h>
#include <signal.h>


void	signal_handler(int signum);

void	asciibinary(unsigned char c, char *binary, unsigned char mask, int i);
void	string_to_binary_recursive(const char *str, char *result);


#endif
