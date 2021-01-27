NAME			= cube_3d

SRCS_LIST		= \
					main.c \
					screenshot.c \
					check_arguments.c \
					map_parsing.c \
					color_parsing.c \
					exit.c \
					utils.c \
					parsing.c \
					check_functions.c \
					event.c \
					initialisation.c \
					raycasting.c \
					raycastingbis.c \
					movement.c \
					sprites.c \
					spritesbis.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

FOLDER			= srcs

LIBFT 			= libft_19
MLX 			= minilibx_metal

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft_19 -lft

METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@make extra -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) $(METAL_MLX) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -o $@ -c $<

clean:
				@$(RM) $(OBJS)
				@make clean -C $(MLX)
				@make clean -C $(LIBFT)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) libmlx.dylib
				@$(RM) img.bmp
				@make fclean -C $(LIBFT)

re:				fclean all

run:			all
				./cube_3d test.cub

.PHONY: 		all fclean clean re