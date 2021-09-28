/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:34:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/21 07:57:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "enum/e_ret.h"

t_ctx	*phi_ctx_get(void)
{
	static t_ctx	ctx = {0, 0, 0, 0, -1, 0, 0, PTHREAD_MUTEX_INITIALIZER};

	return (&ctx);
}
