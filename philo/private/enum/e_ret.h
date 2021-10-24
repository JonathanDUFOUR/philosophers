/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:39:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 14:23:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	AC_ERR,
	FORMAT_ERR,
	LIMITS_ERR,
	MALLOC_ERR,
	USLEEP_ERR,
	PRINTF_ERR,
	MUTEX_LOCK_ERR,
	SIMULATION_RUN,
	SIMULATION_STOP,
	MUTEX_UNLOCK_ERR,
	PTHREAD_JOIN_ERR,
	MUTEX_DESTROY_ERR,
	PTHREAD_CREATE_ERR,
	GET_TIME_OF_DAY_ERR
};

#endif
