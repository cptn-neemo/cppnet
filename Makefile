CXX = g++
LIB = ./src/build/cppnet.a
MFLAGS = -f ./src/Makefile --no-print-directory
SRC = $(wildcard src/*/*.cpp)

all: demo

demo: demo.cpp ${LIB} ${SRC}
	cd src && make && cd ..
	${CXX} -o demo demo.cpp ${LIB}

clean: demo
	-rm demo
