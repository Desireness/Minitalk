CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente
SRC_SERVER = server.c
SRC_CLIENT = client.c

# Archivos objeto
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# Nombre de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client

# Ruta de la librería
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Incluir los archivos de cabecera de libft
INC = -I$(LIBFT_DIR)

# Regla principal: compilar ambos ejecutables
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

# Compilar el servidor
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@echo "Building $(NAME_SERVER)..."
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(CFLAGS) $(LIBFT)
	@echo "🎉 Build SUCCESS! $(NAME_SERVER) created!"

# Compilar el cliente
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@echo "Building $(NAME_CLIENT)..."
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(CFLAGS) $(LIBFT)
	@echo "🎉 Build SUCCESS! $(NAME_CLIENT) created!"; \
	echo "  ____                              _     ____  "; \
    echo " / ___| _   _  ___ ___ ___  ___ ___| |  _|  _ \ "; \
    echo " \___ \| | | |/ __/ __/ _ \/ __/ __| | (_) | | |"; \
    echo "  ___) | |_| | (_| (_|  __/\__ \__ \_|  _| |_| |"; \
    echo " |____/ \__,_|\___\___\___||___/___(_) (_)____/ "; \

# Compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) clean -C $(LIBFT_DIR)

# Eliminar los archivos objeto y los ejecutables
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Regenerar todo (limpiar y compilar de nuevo)
re: fclean all

# Ejecutar el servidor
run_server: $(NAME_SERVER)
	./$(NAME_SERVER)

# Ejecutar el cliente (necesita PID y mensaje)
run_client: $(NAME_CLIENT)
	./$(NAME_CLIENT) $(ARGS)

# Llamar al Makefile de libft para compilar la librería
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re run_server run_client

