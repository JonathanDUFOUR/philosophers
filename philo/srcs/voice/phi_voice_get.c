/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_voice_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:12:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/21 15:03:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_mutex.h"

t_mutex	*phi_voice_get(void)
{
	static t_mutex	voice = PTHREAD_MUTEX_INITIALIZER;

	return (&voice);
}
