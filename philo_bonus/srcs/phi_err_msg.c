/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:56:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/12 13:13:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "colors.h"
#include "err_msg_lookup.h"

int	phi_err_msg(int const err)
{
	int	i;

	printf(RED "Error:\n");
	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	printf("%s\n" WHITE, g_err_msg[i].msg);
	return (err);
}
