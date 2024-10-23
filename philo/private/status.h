/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:43:17 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/21 10:43:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum e_status	t_status;

enum e_status
{
	OK,
	ERR_ARGUMENT_COUNT,
	ERR_PARSE_U8_EMPTY_STRING,
	ERR_PARSE_U8_NON_DIGIT,
	ERR_PARSE_U8_OVERFLOW,
	ERR_PARSE_U16_EMPTY_STRING,
	ERR_PARSE_U16_NON_DIGIT,
	ERR_PARSE_U16_OVERFLOW,
	ERR_NUMBER_OF_PHILOSOPHERS,
	ERR_MALLOC,
	STATUS_COUNT
};

#endif
