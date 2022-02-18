CXX = gcc
CXXFLAGS = -g -Wall -I. -IInclude
LIBS = -L./Libs -lglew32 -lopengl32 -lglfw3dll -lpthread -lLCStr

APPNAME = main

SRCFILES := $(wildcard *.c)
OBJS := $(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^


all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(APPNAME) $(LIBS)