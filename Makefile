CC = g++
CFLAGS = -c -g -Wall
DEPS = BST.h HTable.h
LDFLAGS = 
SOURCES = main.cpp BST.cpp HTable.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

main.o : main.cpp BST.h HTable.h
	$(CC) $(CFLAGS) main.cpp

BST.o : BST.cpp BST.h 
	$(CC) $(CFLAGS) BST.cpp

HTable.o : HTable.cpp HTable.h
	$(CC) $(CFLAGS) HTable.cpp

clean:
	rm $(EXECUTABLE) $(OBJECTS)

