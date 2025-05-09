/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:51:49 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 16:59:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# include "status.h"
# include <stddef.h>

typedef struct s_error_message	t_error_message;

struct s_error_message
{
	char const *const	s;
	size_t const		len;
};

# define ERR_MSG_ARGUMENT_COUNT \
"wrong number of arguments"

# define ERR_MSG_FORK \
"fork: failed to create another process"

# define ERR_MSG_NUMBER_OF_PHILOSOPHERS \
"number_of_philosophers must be greater than 0"

# define ERR_MSG_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT \
"number_of_times_each_philosopher_must_eat must be greater than 0"

# define ERR_MSG_MALLOC \
"malloc: failed to allocate memory"

# define ERR_MSG_PARSE_U8_EMPTY \
"parse_u8: string is empty"

# define ERR_MSG_PARSE_U8_NON_DIGIT \
"parse_u8: string contains a non-digit character"

# define ERR_MSG_PARSE_U8_OVERFLOW \
"parse_u8: parsed value does not fit in a u8"

# define ERR_MSG_PARSE_U16_EMPTY \
"parse_u16: string is empty"

# define ERR_MSG_PARSE_U16_NON_DIGIT \
"parse_u16: string contains a non-digit character"

# define ERR_MSG_PARSE_U16_OVERFLOW \
"parse_u16: parsed value does not fit in a u16"

# define ERR_MSG_PTHREAD_CREATE \
"pthread_create: failed to create another thread"

# define ERR_MSG_PTHREAD_MUTEX_INIT \
"pthread_mutex_init: failed to initialize a mutex"

# define ERR_MSG_SEM_OPEN \
"sem_open: failed to create another semaphore"

static t_error_message const	g_error_messages[STATUS_COUNT] = {
[OK] = {
	.s = NULL,
	.len = 0
},
[ERR_ARGUMENT_COUNT] = {
	.s = ERR_MSG_ARGUMENT_COUNT "\n",
	.len = sizeof(ERR_MSG_ARGUMENT_COUNT),
},
[ERR_FORK] = {
	.s = ERR_MSG_FORK "\n",
	.len = sizeof(ERR_MSG_FORK),
},
[ERR_NUMBER_OF_PHILOSOPHERS] = {
	.s = ERR_MSG_NUMBER_OF_PHILOSOPHERS "\n",
	.len = sizeof(ERR_MSG_NUMBER_OF_PHILOSOPHERS),
},
[ERR_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT] = {
	.s = ERR_MSG_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT "\n",
	.len = sizeof(ERR_MSG_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT),
},
[ERR_MALLOC] = {
	.s = ERR_MSG_MALLOC "\n",
	.len = sizeof(ERR_MSG_MALLOC),
},
[ERR_PARSE_U8_EMPTY_STRING] = {
	.s = ERR_MSG_PARSE_U8_EMPTY "\n",
	.len = sizeof(ERR_MSG_PARSE_U8_EMPTY),
},
[ERR_PARSE_U8_NON_DIGIT] = {
	.s = ERR_MSG_PARSE_U8_NON_DIGIT "\n",
	.len = sizeof(ERR_MSG_PARSE_U8_NON_DIGIT),
},
[ERR_PARSE_U8_OVERFLOW] = {
	.s = ERR_MSG_PARSE_U8_OVERFLOW "\n",
	.len = sizeof(ERR_MSG_PARSE_U8_OVERFLOW),
},
[ERR_PARSE_U16_EMPTY_STRING] = {
	.s = ERR_MSG_PARSE_U16_EMPTY "\n",
	.len = sizeof(ERR_MSG_PARSE_U16_EMPTY),
},
[ERR_PARSE_U16_NON_DIGIT] = {
	.s = ERR_MSG_PARSE_U16_NON_DIGIT "\n",
	.len = sizeof(ERR_MSG_PARSE_U16_NON_DIGIT),
},
[ERR_PARSE_U16_OVERFLOW] = {
	.s = ERR_MSG_PARSE_U16_OVERFLOW "\n",
	.len = sizeof(ERR_MSG_PARSE_U16_OVERFLOW),
},
[ERR_PTHREAD_CREATE] = {
	.s = ERR_MSG_PTHREAD_CREATE "\n",
	.len = sizeof(ERR_MSG_PTHREAD_CREATE),
},
[ERR_PTHREAD_MUTEX_INIT] = {
	.s = ERR_MSG_PTHREAD_MUTEX_INIT "\n",
	.len = sizeof(ERR_MSG_PTHREAD_MUTEX_INIT),
},
[ERR_SEM_OPEN] = {
	.s = ERR_MSG_SEM_OPEN "\n",
	.len = sizeof(ERR_MSG_SEM_OPEN),
},
};

#endif
