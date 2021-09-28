/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_atou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:37:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 17:51:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_int.h"

t_lint	phi_atol(char const *s)
{
	t_lint	res;

	res = 0;
	while (phi_is_space(*s))
		++s;
	if (*s == '+')
		++s;
	while (phi_is_digit(*s))
	{
		res *= 10;
		res += *s - '0';
		++s;
	}
	return (res);
}
