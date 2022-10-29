/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:58:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/29 06:56:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define BLACK_FG	"\033[38;2;0;0;0m"
# define RED_FG		"\033[38;2;255;0;0m"
# define GREEN_FG	"\033[38;2;0;255;0m"
# define BLUE_FG	"\033[38;2;0;0;255m"
# define YELLOW_FG	"\033[38;2;255;255;0m"
# define MAGENTA_FG	"\033[38;2;255;0;255m"
# define CYAN_FG	"\033[38;2;0;255;255m"
# define WHITE_FG	"\033[38;2;255;255;255m"

# define BLACK_BG	"\033[48;2;0;0;0m"
# define RED_BG		"\033[48;2;255;0;0m"
# define GREEN_BG	"\033[48;2;0;255;0m"
# define BLUE_BG	"\033[48;2;0;0;255m"
# define YELLOW_BG	"\033[48;2;255;255;0m"
# define MAGENTA_BG	"\033[48;2;255;0;255m"
# define CYAN_BG	"\033[48;2;0;255;255m"
# define WHITE_BG	"\033[48;2;255;255;255m"

# define BOLD		"\033[1m"
# define BLINK		"\033[5m"

# define RESET		"\033[0m"

#endif
