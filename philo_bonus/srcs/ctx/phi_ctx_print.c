/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:07:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 18:05:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_ctx.h"

void	phi_ctx_print(void)
{
	t_ctx *const	ctx = phi_ctx_get();

	printf("ctx->nb_philo:       %li\n", ctx->nb_philo);
	printf("ctx->time_to_die:    %li\n", ctx->time_to_die);
	printf("ctx->time_to_eat:    %li\n", ctx->time_to_eat);
	printf("ctx->time_to_sleep:  %li\n", ctx->time_to_sleep);
	printf("ctx->required_meals: %li\n", ctx->required_meals);
}
