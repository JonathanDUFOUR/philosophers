/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_state_msg.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:02:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/03 15:18:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_STATE_MSG_H
# define LOOKUP_STATE_MSG_H

# include <stddef.h>
# include "type/t_int.h"
# include "enum/e_state.h"

typedef struct s_state_msg	t_state_msg;

struct s_state_msg
{
	t_hhuint const	state;
	char const		*msg;
};

static t_state_msg const	g_state_msg[] = {
{TOOK_FORK, "has taken a fork"},
{EATING, "is eating"},
{SLEEPING, "is sleeping"},
{THINKING, "is thinking"},
{DEAD, "died"},
{0, NULL}
};

#endif
