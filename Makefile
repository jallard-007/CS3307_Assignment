CXX=g++
CXXFLAGS= -std=c++11 -Wall -Wpedantic -Wextra -Wconversion -Werror

default:
	make all

all: main.o request.o game.o
	$(CXX) -o assignment1 main.o request.o game.o $(CXXFLAGS) -lcurl

main.o: main.cpp
	$(CXX) -c main.cpp $(CXXFLAGS)

request.o: request.cpp
	$(CXX) -c request.cpp $(CXXFLAGS)

game.o: game.cpp
	$(CXX) -c game.cpp $(CXXFLAGS)

clean:
	rm -f main.o request.o game.o assignment1