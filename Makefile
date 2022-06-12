CXX = g++
CXXFLAGS = -g -Wall -I. -I3rdParty -Isrc -I3rdParty/LCMaths
LIBS = -LLibs -lGLEW -lglfw3 -lGL -lpthread -lm
WLIBS = -LLibs/DLLs -lopengl32 -lglew32 -lglfw3 -lpthread -lm

APPNAME = main

SRCFILES := $(notdir $(wildcard src/*.cpp))
SRCFILES += $(notdir $(wildcard *.cpp))
OBJS := $(addprefix obj/, $(patsubst %.cpp, %.o, $(SRCFILES)))
OBJS += obj/LCMaths.o

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(APPNAME) $(WLIBS)

maths: 3rdParty/LCMaths/LCMaths.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/LCMaths.o $^

clean:
	rm obj/*.o
