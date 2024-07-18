# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Werror -Wall -Wextra -g3

# Nome do arquivo fonte e do executável
SRC = ft_sort_int_tab.c
OBJ = $(SRC:.c=.o)
TARGET = sort

# Regra padrão para compilar tudo
all: $(TARGET)

# Regra para compilar o arquivo objeto
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $<\n"

# Regra para compilar o executável
$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "[ COMPILATION COMPLETE !!! ]"

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJ)

# Regra para limpar tudo, incluindo o executável
fclean: clean
	rm -f $(TARGET)

# Regra para recompilar tudo do zero
re: fclean all

# Tester size padrão:
size ?= 8

# Tester
test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@./sort $(ARG)

# Declaração de phony targets
.PHONY: all clean fclean re