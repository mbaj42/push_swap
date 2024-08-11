# Variables
PUSH_SWAP = push_swap
LIBFT_A = libftprintf.a
OBJ_DIR = obj/
COMP = gcc -Wall -Werror -Wextra -I srcs -c

S_SRC_DIR = shared/
P_SRC_DIR = pushswap/
LIBFT = srcs/

S_SRC = create_frame.c \
        display_stacks.c \
        do_pa.c \
        do_pb.c \
        do_ra.c \
        do_rb.c \
        do_rr.c \
        do_rra.c \
        do_rrb.c \
        do_rrr.c \
        do_sa.c \
        do_sb.c \
        do_ss.c \
        fill_stack_a.c \
        push_swap_error.c \
        push_swap_free.c \
        stack_add_end.c \
        stack_add_top.c \
        stack_del_top.c \
	utils_display_stacks.c

P_SRC = find_biggest_smallest.c \
        find_median.c \
        find_moves.c \
        find_stack_len.c \
        insertion_solve_half.c \
        insertion_solve_quarters.c \
        push_median.c \
        push_quarters.c \
        push_swap.c \
        reset_moves.c \
        solve_max_5.c \
        solver.c \
        sorted.c \
        push_quaters_utils.c \
        moves_to_start.c

S_OBJ = $(S_SRC:%.c=$(OBJ_DIR)%.o)
P_OBJ = $(P_SRC:%.c=$(OBJ_DIR)%.o)
OBJ = $(S_OBJ) $(P_OBJ)

# Default rule
all: do_libft $(OBJ_DIR) $(PUSH_SWAP)
	@echo "\\n PUSH_SWAP COMPLETE \\n"

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created: Object directory"

# Link final executable
$(PUSH_SWAP): $(OBJ)
	gcc $(OBJ) $(LIBFT_A) -o push_swap -I includes -I libft/includes

# Compile shared source files
$(OBJ_DIR)%.o: $(S_SRC_DIR)%.c
	@echo "Creating: $@"
	@$(COMP) $< -o $@

# Compile push_swap source files
$(OBJ_DIR)%.o: $(P_SRC_DIR)%.c
	@echo "Creating: $@"
	@$(COMP) $< -o $@

# Build libft
do_libft:
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_A) .

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(LIBFT_A)
	@make -C $(LIBFT) clean
	@echo "\\n Cleaned libft object files \\n"

fclean: clean
	@rm -f $(PUSH_SWAP) $(LIBFT_A)
	@make -C $(LIBFT) fclean
	@echo "\\n Cleaned $(PUSH_SWAP) \\n"

# Rebuild everything
re: fclean all

# Specify phony targets
.PHONY: all clean fclean re
