# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:42:34 by hcavet            #+#    #+#              #
#    Updated: 2024/10/16 13:49:51 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IDIR	=	include/
SDIR	=	src/

CFILES	=	ft_printf.c		\
			ft_display.c	\
			ft_string.c		\
			ft_flags.c		\
			ft_isflag.c
SRCS	=	$(addprefix $(SDIR), $(CFILES))
OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	rm -f
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a
TNAME	=	testftprintf

all		:	$(NAME)

$(NAME)	:	$(OBJS) header
			echo "Creating archive..."
			$(AR) $(NAME) $(OBJS)
			echo "Generating index..."
			ranlib $(NAME)
			echo "$(GREEN)[OK] ft_printf is ready!$(RESET)"

bonus	:	all

.c.o	:
			echo "Compiling $<..."
			$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $(<:.c=.o)

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) $(IDIR)

clean	:
			echo "Removing object files..."
			$(RM) $(OBJS)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) norm debug clean fclean re header test bonus

RED     = \033[31m
ORANGE  = \033[38;5;214m
YELLOW  = \033[33m
GREEN   = \033[32m
BLUE    = \033[34m
VIOLET  = \033[38;5;93m
ITALIC  = \033[3m
RESET   = \033[0m

header	:
			echo "==============================================="
			echo "$(RED)  __  _                     _         _     __ $(RESET)"
			echo "$(RED) / _|| |                   (_)       | |   / _|$(RESET)"
			echo "$(ORANGE)| |_ | |_      _ __   _ __  _  _ __  | |_ | |_ $(RESET)"
			echo "$(ORANGE)|  _|| __|    | '_ \ | '__|| || '_ \ | __||  _|$(RESET)"
			echo "$(YELLOW)| |  | |_     | |_) || |   | || | | || |_ | |  $(RESET)"
			echo "$(GREEN)|_|   \__|    | .__/ |_|   |_||_| |_| \__||_|  $(RESET)"
			echo "$(BLUE)       ______ | |                              $(RESET)"
			echo "$(BLUE)      |______||_|                              $(RESET)"
			echo "$(ITALIC)$(VIOLET)                     by Ego\n$(RESET)"
			echo "===============================================\n"

test	:	all
			$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(TNAME) 