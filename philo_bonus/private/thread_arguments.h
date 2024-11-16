/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_arguments.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:34:34 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 16:42:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_ARGUMENTS_H
# define THREAD_ARGUMENTS_H

# include <pthread.h>
# include <semaphore.h>

typedef struct s_thread_arguments	t_thread_arguments;

struct s_thread_arguments
{
	pthread_mutex_t	synchronizer;
	sem_t			*start_signal;
};

#endif
