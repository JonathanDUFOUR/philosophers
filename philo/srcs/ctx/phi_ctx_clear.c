/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:16:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 15:22:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_clear(int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_destroy(&ctx->access))
		return (*ret = MUTEX_DESTROY_ERR);
	memset(ctx, 0, sizeof(t_ctx));
	return (*ret = SUCCESS);
}
