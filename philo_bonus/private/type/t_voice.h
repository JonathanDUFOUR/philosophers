/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_voice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:10:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/13 20:14:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VOICE_H
# define T_VOICE_H

# include <pthread.h>

typedef pthread_mutex_t	t_voice;

t_voice	*phi_voice_get(void);

#endif
