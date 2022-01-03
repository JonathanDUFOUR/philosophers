/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_err_msg.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:59:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/03 15:17:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ERR_MSG_H
# define LOOKUP_ERR_MSG_H

# include <stddef.h>
# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const	err;
	char const	*msg;
};

static const t_err_msg		g_err_msg[] = {
{AC_ERR, "wrong argument count"},
{FORMAT_ERR, "wrong argument(s) format"},
{LIMITS_ERR, "input is over LONG_INT_MAX value"},
{MALLOC_ERR, "malloc() failed"},
{USLEEP_ERR, "usleep() failed"},
{PRINTF_ERR, "printf() failed"},
{MUTEX_LOCK_ERR, "pthread_mutex_lock() failed"},
{MUTEX_UNLOCK_ERR, "pthread_mutex_unlock() failed"},
{PTHREAD_JOIN_ERR, "pthread_join() failed"},
{MUTEX_DESTROY_ERR, "pthread_mutex_destroy() failed"},
{PTHREAD_CREATE_ERR, "pthread_create() failed"},
{GET_TIME_OF_DAY_ERR, "gettimeofday() failed"},
{0, NULL}
};

#endif
