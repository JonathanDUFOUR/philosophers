# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 23:18:36 by jodufour          #+#    #+#              #
#    Updated: 2021/10/24 16:24:10 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang -c -o
LINK	=	clang -o
MKDIR	=	mkdir -p
RM		=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME	=	philo

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
PRV_DIR	=	private/

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix ctx/,					\
				phi_ctx_clear.c					\
				phi_ctx_get.c					\
				phi_ctx_init_nb_philo.c			\
				phi_ctx_init_required_meals.c	\
				phi_ctx_init_time_to_die.c		\
				phi_ctx_init_time_to_eat.c		\
				phi_ctx_init_time_to_sleep.c	\
				phi_ctx_init.c					\
			}									\
			${addprefix manager/,				\
				phi_manager_born.c				\
				phi_manager_get.c				\
				phi_manager_init.c				\
				phi_manager_kill.c				\
				phi_manager_routine.c			\
				phi_manager_stop.c				\
			}									\
			${addprefix philo/,					\
				phi_philo_born.c				\
				phi_philo_clear.c				\
				phi_philo_eat.c					\
				phi_philo_init.c				\
				phi_philo_routine.c				\
				phi_philo_sleep.c				\
				phi_philo_state_msg.c			\
				phi_philo_suicide.c				\
				phi_philo_think.c				\
				phi_philo_wait.c				\
			}									\
			${addprefix utils/,					\
				phi_atol.c						\
				phi_is_digit.c					\
				phi_is_space.c					\
				phi_lintlen.c					\
				phi_memdel.c					\
				phi_strcmp.c					\
				phi_strlen.c					\
			}									\
			${addprefix voice/,					\
				phi_voice_clear.c				\
				phi_voice_get.c					\
			}									\
			main.c								\
			phi_err_msg.c						\
			phi_format_check.c					\
			phi_limits_check.c					\
			phi_now.c							\
			phi_run.c							\

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-Wall -Wextra #-Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${PRV_DIR}

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
else \
ifeq (${DEBUG}, 2)
	CFLAGS	+=	-g3 -fsanitize=address
	LDFLAGS	=	-lasan
else \
ifeq (${DEBUG}, 3)
	CFLAGS	+=	-g3 -fsanitize=thread
	LDFLAGS	=	-ltsan
endif

LDFLAGS	+=	-lpthread

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re coffee norm
