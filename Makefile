NAME  := dshala.filler

INC   := include/

LIB   := libft.a

LIB_DIR := libft/

LIBINC := $(LIB_DIR)includes

SRC  = main\
		get_heatmap\
		parse_input\
		place_token\
		record_player_positions\
		conditions

VPATH = src

O_DIR := objects

OBJS  := $(addsuffix .o, $(addprefix $(O_DIR)/, $(SRC)))

CFLAGS := -Wall -Wextra -Werror

CC    := gcc

all: folder $(LIB) $(NAME)
	@echo "Filler has successfully complied!"

$(LIB):
	@$(MAKE) -sC $(LIB_DIR)

folder:
	@mkdir -p $(O_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB_DIR)$(LIB) -o $@

$(O_DIR)/%.o: %.c $(INC) $(LIBINC)
	$(CC) $(CFLAGS) -g -o $@ -c $< -I$(INC) -I$(LIBINC)

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(O_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, folder, re, clean, fclean
