/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:37:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 18:30:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_int.h"

t_lint	phi_atol(char const *str)
{
	t_lint	output;

	output = 0;
	while (phi_is_space(*str))
		++str;
	if (*str == '+')
		++str;
	while (phi_is_digit(*str))
	{
		output *= 10;
		output += *str - '0';
		++str;
	}
	return (output);
}
