/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:08:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 16:48:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stddef.h>
# include <stdbool.h>
# include "type/t_int.h"

int		phi_err_msg(int const err);
int		phi_format_check(char const **av);
int		phi_limits_check(char const *str, t_lint nb);
int		phi_lintlen(t_lint nb);
int		phi_now(t_lint *const now);
int		phi_run(void);
int		phi_strcmp(char const *s0, char const *s1);

void	phi_memdel(void *addr);

bool	phi_is_digit(char const c);
bool	phi_is_space(char const c);

t_lint	phi_atol(char const *str);

size_t	phi_strlen(char const *str);

#endif
