# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:48:19 by jodufour          #+#    #+#              #
#    Updated: 2024/11/09 00:59:23 by jodufour         ###   ########.fr        #
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
SRC := ${addsuffix .c, \
	clean_the_simulation \
	launch_the_simulation \
	main \
	monitor_the_simulation \
	parse_the_arguments \
	philosopher_routine \
	prepare_the_simulation \
	suspend_the_execution_for_n_useconds \
	wait_for_threads \
}

######################################
#            OBJECT FILES            #
######################################
OBJ := ${SRC:.c=.o}
OBJ := ${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP := ${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS := ${strip \
	-c \
	-Wall -Wextra -Werror \
	-MMD -MP \
	-I${PRV_DIR} \
}

LDFLAGS := ${strip \
}

ifeq (${DEBUG}, 1)
	CFLAGS += -gdwarf-4
else ifeq (${DEBUG}, 2)
	 CFLAGS += -g -fsanitize=address
	LDFLAGS += -lasan
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

-include norm.mk
-include coffee.mk
