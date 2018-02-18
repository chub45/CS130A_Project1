CC = g++
CFLAGS = -c -g -Wall
DEPS = BST.h HTable.h
LDFLAGS = 
SOURCES = main.cpp BST.cpp HTable.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lstdc++fs -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) *.cpp

clean:
	rm $(EXECUTABLE) $(OBJECTS)

