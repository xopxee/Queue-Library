CC = gcc
LDFLAGS =
TARGET = main
HEADERS = queue.h
SOURCES = main.c queue.c
DEPENDENCIES = $(HEADERS) $(SOURCES)

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(SOURCES) -o $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)