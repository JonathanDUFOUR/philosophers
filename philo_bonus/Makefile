# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:48:19 by jodufour          #+#    #+#              #
#    Updated: 2024/11/11 02:59:12 by jodufour         ###   ########.fr        #
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
NAME := philo_bonus

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
	${addprefix simulation/, \
		cleanup \
		launch \
		monitor \
		setup \
	} \
	main \
	parse_arguments \
	philosopher_life_cycle \
	suspend_execution_for_n_useconds \
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
