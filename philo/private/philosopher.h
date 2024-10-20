/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:35:33 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/21 00:13:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <bits/pthreadtypes.h>

typedef struct s_philosopher	t_philosopher;

struct s_philosopher
{
	pthread_mutex_t const	*forks[2];
};

#endif
