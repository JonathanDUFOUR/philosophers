/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:23:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/19 16:24:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_manager.h"

t_manager	*phi_manager_get(void)
{
	static t_manager	manager = {0, NULL};

	return (&manager);
}
