CXX = gcc
CXXFLAGS = -g -Wall -I. -IInclude
LIBS = -LLibs -lGLEW -lglfw3 -lGL -lpthread -lLCStr -lLCMaths -lm

APPNAME = main

SRCFILES := $(wildcard *.c)
OBJS := $(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^


all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(APPNAME) $(LIBS)

clean:
	rm obj/*.o
