/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:56:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 03:09:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "colors.h"
#include "philosophers.h"
#include "err_msg_lookup.h"

int	phi_err_msg(int const err)
{
	int	i;

	write(2, RED "Error:\n", 12);
	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	if (g_err_msg[i].msg)
		write(2, g_err_msg[i].msg, phi_strlen(g_err_msg[i].msg));
	write(2, WHITE "\n", 5);
	return (err);
}
