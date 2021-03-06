NAME    := libft.a

INC     := includes/

OBJ_DIR := objs

CYAN     = \033[36m
RED      = \033[31m

CC      := gcc

CFLAGS  := -Wall -Wextra -Werror

HEADERS := $(shell find includes/ -type f | cut -d "/" -f 2)
BOOL    := $(shell find srcs/bool/ -type f | cut -d "/" -f 3)
CONV    := $(shell find srcs/conv/ -type f | cut -d "/" -f 3)
LST     := $(shell find srcs/lst/ -type f | cut -d "/" -f 3)
MEM     := $(shell find srcs/mem/ -type f | cut -d "/" -f 3)
STR     := $(shell find srcs/str/ -type f | cut -d "/" -f 3)
PRINTF  := $(shell find srcs/printf/ -type f | cut -d "/" -f 3)
OTHERS  := $(shell find srcs/others/ -type f | cut -d "/" -f 3)
PUT     := $(shell find srcs/put/ -type f | cut -d "/" -f 3)


LIB_OBJ  = $(addprefix $(OBJ_DIR)/, $(BOOL:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(CONV:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(LST:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(MEM:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(STR:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(OTHERS:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(PUT:%.c=%.o))
LIB_OBJ += $(addprefix $(OBJ_DIR)/,$(PRINTF:%.c=%.o))

VPATH = srcs/bool:srcs/conv:srcs/lst:srcs/mem:srcs/str:srcs/printf:srcs/others:srcs/put

all: $(NAME)
	@echo "$(CYAN)Creating library$(CYAN)"
	@ar rcs $< $(LIB_OBJ)
	@echo "$(RED)libft has successfully created!$(RED)"

$(NAME): objects $(LIB_OBJ)
	@echo "$(RED)o files has been created$(RED)"

objects:
	@echo "$(CYAN)Creating object folder$(CYAN)"
	@mkdir -p $(OBJ_DIR)
	@echo "$(RED)Object folder has been created$(RED)"

$(OBJ_DIR)/%.o: %.c $(addprefix $(INC), $(HEADERS))
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	@echo "$(CYAN)Removing objects dir$(CYAN)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)Removing library$(CYAN)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, objects, clean, fclean, re
