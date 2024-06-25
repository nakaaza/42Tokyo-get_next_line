# Constants
NAME		= get_next_line.a

SRCS		= get_next_line get_next_line_utils
SRC_FILES	= $(addsuffix .c, $(SRCS))
B_SRCS		= get_next_line_bonus get_next_line_utils_bonus
B_SRC_FILES	= $(addsuffix .c, $(B_SRCS))

OBJ_DIR		= ./obj/
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
B_OBJ_FILES	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRCS)))

BUFFER_SIZE	:= 42

# Verbs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_MAX_COUNT=$(FD_MAX_COUNT)
AR			= ar rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(GREEN)Creating $(NAME)…$(DEF_COLOR)"
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "\n"

bonus: $(B_OBJ_FILES)
	@echo "$(GREEN)Creating $(NAME)…$(DEF_COLOR)"
	$(AR) $(NAME) $(B_OBJ_FILES)
	touch bonus
	@echo "\n"

$(OBJ_DIR)%.o: %.c
	@echo "$(YELLOW)Compiling $<…$(DEF_COLOR)"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n"

clean:
	@echo "$(GREEN)Cleaning object files…$(DEF_COLOR)"
	$(RM) -r $(OBJ_DIR)
	$(RM) bonus
	@echo "\n"

fclean: clean
	@echo "$(GREEN)Cleaning $(NAME)…$(DEF_COLOR)"
	$(RM) $(NAME)
	@echo "\n"

re: fclean all

# tests
test: $(NAME)
	$(CC) $(CFLAGS) -o test test.c $(NAME)
	@echo "$(YELLOW)"
	./test $(FILE_PATH)
	@echo "$(DEF_COLOR)"

test_b: bonus
	$(CC) $(CFLAGS) -o test_b test_b.c $(NAME)
	@echo "$(YELLOW)"
	./test_b $(FILE_PATH1) $(FILE_PATH2) $(FILE_PATH3)
	@echo "$(DEF_COLOR)"

retest: tclean test

retest_b: tclean test_b

tclean: fclean
	@echo "$(GREEN)Cleaning test files…$(DEF_COLOR)"
	$(RM) test test_b


# Colors
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
