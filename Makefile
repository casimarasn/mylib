# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:54:30 by msedeno-          #+#    #+#              #
#    Updated: 2026/02/12 15:50:02 by msedeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# Directories
INC_DIR     = inc
SRC_DIR     = src
OBJ_DIR     = obj

# Source subdirectories
SRC_DIRS    = $(addprefix $(SRC_DIR)/, \
                conversions ctype gnl lists math mem printf put string)

# Correct include path 
INCLUDES    = -I$(INC_DIR)

# Search for .c files in subdirectories (This allows using just filenames in SRC)
vpath %.c $(SRC_DIRS)

# Source files list
SRC = \
    ft_atoi.c ft_atoi_strict.c ft_itoa.c atod.c \
    ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
    ft_tolower.c ft_toupper.c \
    get_next_line.c \
    ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
    ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
    sort_int_array.c ft_abs.c \
    ft_printf.c ft_print_char.c ft_print_format.c ft_print_hexdecma.c \
    ft_print_hexdecmi.c ft_print_nbr.c ft_print_percent.c ft_print_pointer.c \
    ft_print_string.c ft_print_unsigned.c \
    ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
    ft_split.c ft_idx.c ft_strchr.c ft_strdup.c ft_striteri.c \
    ft_strjoin.c ft_strjoin_space.c ft_strlcat.c ft_strlcpy.c \
    ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
    ft_strtrim.c ft_substr.c

# Object paths
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RM = rm -rf
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

# Compilation rule that creates the obj directory if it doesn't exist
$(OBJ_DIR)/%.o: %.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


