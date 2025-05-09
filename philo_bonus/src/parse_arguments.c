/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:37:38 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 21:30:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program_arguments.h"
#include "status.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @return `true` if the given character `c` is a digit, `false` otherwise.
 */
inline static bool
	is_digit(
		char const c
	)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Parses a 8-bits unsigned integer from a string,
 *        and stores it in a given variable.
 *        Leading whitespaces and signs are not supported.
 * 
 * @param s The string to parse.
 * 
 * @param n_addr A reference to the variable to store the parsed value in.
 * 
 * @param status A reference to the status to set if the parsing fails.
 * 
 * @return `true` if the parsing fails, `false` otherwise.
 */
inline static bool
	parse_u8(
		char const *s,
		uint8_t *const n_addr,
		t_status *const status
	)
{
	uint8_t	n;

	if (*s == 0)
		return (*status = ERR_PARSE_U8_EMPTY_STRING, true);
	while (*s == '0')
		++s;
	if (*s == 0)
		return (*n_addr = 0, false);
	if (!is_digit(*s))
		return (*status = ERR_PARSE_U8_NON_DIGIT, true);
	n = 0;
	while (is_digit(*s))
	{
		if (__builtin_mul_overflow(n, 10, &n) || \
			__builtin_add_overflow(n, *s - '0', &n))
			return (*status = ERR_PARSE_U8_OVERFLOW, true);
		++s;
	}
	if (*s)
		return (*status = ERR_PARSE_U8_NON_DIGIT, true);
	return (*n_addr = n, false);
}

/**
 * @brief Parses a 16-bits unsigned integer from a string,
 *        and stores it in a given variable.
 *        Leading whitespaces and signs are not supported.
 * 
 * @param s The string to parse.
 * 
 * @param n_addr A reference to the variable to store the parsed value in.
 * 
 * @param status A reference to the status to set if the parsing fails.
 * 
 * @return `true` if the parsing fails, `false` otherwise.
 */
inline static bool
	parse_u16(
		char const *s,
		uint16_t *const n_addr,
		t_status *const status
	)
{
	uint16_t	n;

	if (*s == 0)
		return (*status = ERR_PARSE_U16_EMPTY_STRING, true);
	while (*s == '0')
		++s;
	if (*s == 0)
		return (*n_addr = 0, false);
	if (!is_digit(*s))
		return (*status = ERR_PARSE_U16_NON_DIGIT, true);
	n = 0;
	while (is_digit(*s))
	{
		if (__builtin_mul_overflow(n, 10, &n) || \
			__builtin_add_overflow(n, *s - '0', &n))
			return (*status = ERR_PARSE_U16_OVERFLOW, true);
		++s;
	}
	if (*s)
		return (*status = ERR_PARSE_U16_NON_DIGIT, true);
	return (*n_addr = n, false);
}

/**
 * @brief Checks that the arguments passed to the program are valid,
 *        and if so, parses them and save their values in a given structure.
 *        If the arguments are invalid, sets the given status accordingly.
 * 
 * @param arguments A reference to the structure where to store the arguments
 *        once parsed.
 * 
 * @param av The arguments passed to the program.
 * 
 * @param status A reference to the status to set if an argument is invalid.
 * 
 * @return `true` if an argument is invalid, `false` otherwise.
 */
bool
	parse_arguments(
		t_program_arguments *const arguments,
		char const *const *const av,
		t_status *const status
	)
{
	if (parse_u8(av[1], &arguments->number_of_philosophers, status) || \
		parse_u16(av[2], &arguments->time_to_die, status) || \
		parse_u16(av[3], &arguments->time_to_eat, status) || \
		parse_u16(av[4], &arguments->time_to_sleep, status))
		return (true);
	if (arguments->number_of_philosophers == 0)
		return (*status = ERR_NUMBER_OF_PHILOSOPHERS, true);
	if (av[5] == NULL)
	{
		arguments->number_of_times_each_philosopher_must_eat = 0;
		return (false);
	}
	if (parse_u8(
			av[5],
			&arguments->number_of_times_each_philosopher_must_eat,
			status
		))
		return (true);
	if (arguments->number_of_times_each_philosopher_must_eat == 0)
		return (*status = ERR_NUMBER_OF_TIMES_EACH_PHILOSOPHER_MUST_EAT, true);
	return (false);
}
