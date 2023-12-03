# Definir el compilador
CC=g++

# Opciones de compilación
CFLAGS=-std=c++11

# Opciones de vinculación para OpenCV
OPENCV_LIBS=$(shell pkg-config --cflags --libs opencv4)

# Ruta al directorio de binarios
BINDIR=../../bin

# Nombre del ejecutable
EXECUTABLE=$(BINDIR)/lumus

# Regla principal
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): lumus.cpp
	$(CC) $(CFLAGS) lumus.cpp -o $(EXECUTABLE) $(OPENCV_LIBS)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(EXECUTABLE)
