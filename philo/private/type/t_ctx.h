/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:35:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 15:20:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# include <pthread.h>
# include "type/t_int.h"
# include "type/t_mutex.h"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	t_lint	nb_philo;
	t_lint	time_to_die;
	t_lint	time_to_eat;
	t_lint	time_to_sleep;
	t_lint	required_meals;
	t_lint	start;
	t_mutex	access;
};

int		phi_ctx_clear(int *const ret);
int		phi_ctx_init_nb_philo(char const *str);
int		phi_ctx_init_time_to_die(char const *str);
int		phi_ctx_init_time_to_eat(char const *str);
int		phi_ctx_init_time_to_sleep(char const *str);
int		phi_ctx_init_required_meals(char const *str);
int		phi_ctx_init(char const **av);

t_ctx	*phi_ctx_get(void);

#endif
