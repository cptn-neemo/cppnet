CXX = g++
LIB = ./src/build/cppnet.a
MFLAGS = -f ./src/Makefile --no-print-directory
SRC = $(wildcard src/*/*.cpp)

all: demo test1

test1: test1.cpp ${LIB} ${SRC}
	cd src && make && cd ..
	${CXX} -o test1 test1.cpp ${LIB}

demo: demo.cpp ${LIB} ${SRC}
	cd src && make && cd ..
	${CXX} -o demo demo.cpp ${LIB}

clean: demo
	-rm demo
