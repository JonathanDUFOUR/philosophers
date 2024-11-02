/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:43:17 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 23:58:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum e_status	t_status;

enum e_status
{
	OK,
	ERR_ARGUMENT_COUNT,
	ERR_NUMBER_OF_PHILOSOPHERS,
	ERR_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT,
	ERR_MALLOC,
	ERR_PARSE_U8_EMPTY_STRING,
	ERR_PARSE_U8_NON_DIGIT,
	ERR_PARSE_U8_OVERFLOW,
	ERR_PARSE_U16_EMPTY_STRING,
	ERR_PARSE_U16_NON_DIGIT,
	ERR_PARSE_U16_OVERFLOW,
	ERR_PTHREAD_CREATE,
	STATUS_COUNT
};

#endif
