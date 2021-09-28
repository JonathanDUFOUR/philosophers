/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:08:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/21 03:15:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include "type/t_int.h"

int		phi_err_msg(int const err);
int		phi_format_check(char const **av);
int		phi_ilimits_check(char const *s, int nb);
int		phi_init(char const **av);
int		phi_run(void);
int		phi_strcmp(char const *s1, char const *s2);
int		phi_lintlen(t_lint nb);
int		phi_limits_check(char const *s, t_lint nb);

void	phi_memdel(void *addr);

void	*phi_routine(void *param);

bool	phi_is_digit(char const c);
bool	phi_is_space(char const c);

t_uint	phi_atou(char const *s);

t_lint	phi_atol(char const *s);
t_lint	phi_now(void);

#endif
