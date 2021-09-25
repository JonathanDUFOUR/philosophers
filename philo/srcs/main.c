/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:37:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 17:46:35 by jodufour         ###   ########.fr       */
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
		ret = phi_format_check(av);
		if (ret == SUCCESS)
			ret = phi_ctx_init(av);
		if (ret == SUCCESS)
			ret = phi_run();
	}
	else
		ret = AC_ERR;
	if (ret != SUCCESS)
		phi_err_msg(ret);
	return (SUCCESS);
}
