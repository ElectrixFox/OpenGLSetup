CXX = g++
CXXFLAGS = -g -Wall -I. -I3rdParty -Isrc -Isrc/Rendering -Isrc/ECS -I3rdParty/LCMaths -I3rdParty/GLFW
LIBS = -lpthread -lm

ifeq ($(OS), Windows_NT)
	LIBS += -LLibs/DLLs -lopengl32 -lglew32 -lglfw3
else
	LIBS += -LLibs -lGLEW -lglfw3 -lGL
endif

APPNAME = main

SRCFILES := $(notdir $(wildcard src/Rendering/*.cpp))
SRCFILES += $(notdir $(wildcard src/ECS/*.cpp))
SRCFILES += $(notdir $(wildcard src/*.cpp))
SRCFILES += $(notdir $(wildcard *.cpp))

OBJS := $(addprefix obj/, $(patsubst %.cpp, %.o, $(SRCFILES)))
EXCLUDE := $(OBJS)

OBJS += obj/LCMaths.o

obj/%.o: src/Rendering/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
	
obj/%.o: src/ECS/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(APPNAME) $(LIBS)

maths: 3rdParty/LCMaths/LCMaths.cpp
	$(CXX) $(CXXFLAGS) -c -o obj/LCMaths.o $^

clean:
	rm $(EXCLUDE)

clean_all:
	rm obj/*.o

