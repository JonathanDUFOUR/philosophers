/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_now.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:26:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/18 20:18:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>
#include "type/t_int.h"
#include "type/t_timeval.h"
#include "enum/e_ret.h"

int	phi_now(t_lint *now)
{
	t_timeval	tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (GET_TIME_OF_DAY_ERR);
	*now = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return (SUCCESS);
}
