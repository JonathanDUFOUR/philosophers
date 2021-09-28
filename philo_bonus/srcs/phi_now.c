/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_now.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:26:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 21:31:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>
#include "type/t_int.h"
#include "type/t_timeval.h"

/*
**	return the now-time value in msec
**	return -1 if an error occurs
*/
t_lint	phi_now(void)
{
	t_timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		return (-1);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
