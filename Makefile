# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 15:29:55 by gothmane          #+#    #+#              #
#    Updated: 2023/01/07 18:46:24 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= so_long

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= ./so_long_mandatory/ft_free_memory.c ./so_long_mandatory/exit_hook.c ./so_long_mandatory/ft_check_ber.c ./so_long_mandatory/ft_check_inside.c ./so_long_mandatory/ft_check_map_ecp.c ./so_long_mandatory/ft_check_up_down.c ./so_long_mandatory/ft_check_walls.c ./so_long_mandatory/ft_ckeck_string_lent.c ./so_long_mandatory/ft_file_to_image.c ./so_long_mandatory/ft_get_map.c ./so_long_mandatory/ft_printf.c ./so_long_mandatory/ft_putchar.c ./so_long_mandatory/ft_putnbr.c ./so_long_mandatory/ft_putstr.c ./so_long_mandatory/ft_render_frame_backround.c ./so_long_mandatory/ft_render_frame_ecp.c ./so_long_mandatory/get_next_line.c ./so_long_mandatory/get_next_line_utils.c ./so_long_mandatory/key_hook.c ./so_long_mandatory/new_map.c ./so_long_mandatory/so_long.c

SRCS_B 	= ./so_long_bonus/exit_hook.c ./so_long_bonus/ft_check_ber.c ./so_long_bonus/ft_free_memory.c ./so_long_bonus/ft_check_map_ecp.c ./so_long_bonus/ft_check_up_down.c ./so_long_bonus/ft_check_inside.c ./so_long_bonus/ft_check_walls.c ./so_long_bonus/ft_ckeck_string_lent.c ./so_long_bonus/ft_file_to_image.c ./so_long_bonus/ft_get_map.c ./so_long_bonus/ft_itoa.c ./so_long_bonus/ft_move_m.c ./so_long_bonus/ft_printf.c ./so_long_bonus/ft_putchar.c ./so_long_bonus/ft_putstr.c ./so_long_bonus/ft_render_frame_backround.c ./so_long_bonus/ft_render_frame_ecp.c ./so_long_bonus/get_next_line.c ./so_long_bonus/get_next_line_utils.c ./so_long_bonus/key_hook.c ./so_long_bonus/move.c ./so_long_bonus/new_map.c ./so_long_bonus/so_long.c ./so_long_bonus/ft_rand.c

M_OBJ	= $(SRCS:.c=.o)

B_OBJ	= $(SRCS_B:.c=.o)

RM = rm -rf

RM_S = rm -rf ./so_long_mandatory/so_long ./so_long_bonus/so_long

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${M_OBJ}
		@${CC} ${CFLAGS} ${M_OBJ}  -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		@mv so_long ./so_long_mandatory

bonus: ${B_OBJ}
		@${CC} ${CFLAGS} ${B_OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		@mv so_long ./so_long_bonus

all:	${NAME} 

clean:	
	@${RM} ${B_OBJ} ${M_OBJ} 

fclean: clean
	@$(RM) $(NAME) $(RM_S)

re: fclean all