# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:48:19 by jodufour          #+#    #+#              #
#    Updated: 2024/10/23 22:22:13 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
   CC := ${shell which cc}
 LINK := ${shell which cc}
MKDIR := ${shell which mkdir} -p
   RM := ${shell which rm} -rf

######################################
#             EXECUTABLE             #
######################################
NAME := philo

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR := src
OBJ_DIR := obj
PRV_DIR := private

######################################
#            SOURCE FILES            #
######################################
SRC := \
	${addsuffix .c, \
		main \
		parse_the_arguments \
		prepare_the_simulation \
		run_the_simulation \
		watch_the_time \
	} \

######################################
#            OBJECT FILES            #
######################################
OBJ := ${SRC:.c=.o}
OBJ := ${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP := ${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS := \
	-c \
	-Wall -Wextra -Werror \
	-Wno-logical-op-parentheses \
	-MMD -MP \
	-I${PRV_DIR} \

LDFLAGS := 

ifeq (${DEBUG}, 1)
	CFLAGS += -gdwarf-4
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

.PHONY: all
all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

.PHONY: clean
clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

.PHONY: fclean
fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

.PHONY: re
re: clean all

.PHONY: fre
fre: fclean all
