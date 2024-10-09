# Nombre del compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall -g

# Nombre del ejecutable
EXEC = buffer_program

# Archivos fuente
SRC = main.c buffer.c

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Regla por defecto: compilar y enlazar el programa
all: $(EXEC)

# Regla para compilar el programa
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regla para compilar archivos fuente en archivos objeto
%.o: %.c buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(EXEC)

# Limpiar archivos generados y temporales
cleanall: clean
	rm -f *~

# Regla para ejecutar el programa
run: $(EXEC)
	./$(EXEC)