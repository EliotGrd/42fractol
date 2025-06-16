NAME = fractol

SRC_PATH = srcs/
SRC = color.c handle_keys.c mathing.c render.c main.c exit.c init.c fractals.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INC = -Iincludes -Ilibft -Iminilibx-linux

PURPLE = \033[0;35m
NC = \033[0m

LIBFT_PATH = libft/
LIBFT_AR = libft/libft.a
MLX_PATH = minilibx-linux/
MLX_AR = minilibx-linux/libmlx.a
RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(MLX_AR) $(LIBFT_AR) $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME) : $(LIBFT_AR) $(MLX_AR) $(OBJS)
	@echo "\n$(PURPLE)  Compiling Fractol...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_AR) $(LIBFT_AR) $(INC) $(MLXFLAGS) -o $(NAME)
	@echo "\n$(PURPLE)  Ready ✓$(NC)"

$(MLX_AR) :
	@echo "\n$(PURPLE)  Compiling MLX... $(NC)"
	@make -s -C $(MLX_PATH)
	@echo "\n$(PURPLE)  Done ✓ $(NC)"

$(LIBFT_AR) : 
	@echo "\n$(PURPLE)  Compiling LIBFT...$(NC)"
	@make -s -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

clean :
	@echo "\n$(PURPLE)  Cleaning objects files... $(NC)"
	@rm -rf $(OBJ_PATH)
	@make clean -s -C $(LIBFT_PATH)
	@make clean -s -C $(MLX_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

fclean : clean
	@echo "\n$(PURPLE)  Cleaning Fractol...$(NC)"
	@$(RM) $(NAME)
	@make fclean -s -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

$(OBJS) : $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH)

re : fclean all

.PHONY: all re clean fclean
