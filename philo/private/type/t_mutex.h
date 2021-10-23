/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mutex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:05:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/21 14:39:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MUTEX_H
# define T_MUTEX_H

# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

t_mutex	*phi_voice_get(void);

#endif
