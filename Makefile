CXX = gcc
CXXFLAGS = -g -Wall -I. -I3rdParty -Isrc
LIBS = -LLibs -lGLEW -lglfw3 -lGL -lpthread -lLCStr -lLCMaths -lm

APPNAME = main

SRCFILES := $(notdir $(wildcard src/*.c))
SRCFILES += $(notdir $(wildcard *.c))
OBJS := $(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

obj/%.o: src/%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(APPNAME) $(LIBS)

clean:
	rm obj/*.o
