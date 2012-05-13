CC=g++
TARGET=bin/SBPRay
OBJ=

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) -c $(OBJ)