TARGET = string
LIBS = -lm
CC = gcc
CFLAGS = -fpermissive -g -Wall -I'./..'
CXX = g++
CXXFLAGS = -fpermissive -g -Wall -I'./..'

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
#	$(CC) $(CFLAGS) -c $< -o $@
	$(CXX) $(CXXFLAGS) -c $< -o $@

#.PRECIOUS: $(TARGET) $(OBJECTS)

.PHONY: clean all default

$(TARGET): $(OBJECTS)
#	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

default: $(TARGET)
all: default

clean:
	-rm -f *.o
	-rm -f $(TARGET)
