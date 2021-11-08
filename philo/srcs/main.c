/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:37:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:02:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	main(int ac, char const **av)
{
	int	ret;

	if (ac == 5 || ac == 6)
	{
		if (phi_format_check(av, &ret)
			|| phi_ctx_init(av, &ret)
			|| phi_run(&ret))
			return (phi_err_msg(ret));
	}
	else
		return (phi_err_msg(AC_ERR));
	return (SUCCESS);
}
