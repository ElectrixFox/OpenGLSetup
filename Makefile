CXX = gcc
CXXFLAGS = -Wall -g -O2 -I. -IInclude
LIBS = -L./Libs -lglew32 -lopengl32 -lglfw3dll -lpthread




all:
	$(CXX) $(CXXFLAGS) main.c -o main $(LIBS)