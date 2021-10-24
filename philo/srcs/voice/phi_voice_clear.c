/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_voice_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:20:13 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 14:23:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_mutex.h"
#include "enum/e_ret.h"

int	phi_voice_clear(int *const ret)
{
	t_mutex *const	voice = phi_voice_get();

	if (pthread_mutex_destroy(voice))
		return (*ret = MUTEX_DESTROY_ERR);
	return (*ret = SUCCESS);
}
