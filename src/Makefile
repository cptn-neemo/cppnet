CC = g++
LIB = ./build/cppnet.a
FLAGS = -Wall -Werror -g

SRC = $(wildcard ./*/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

lib: $(OBJS)

%.o: %.cpp
	$(CC) -o $@ -c $^ $(FLAGS)
	@ar rvs $(LIB) $@

clean:
	@rm -f */*.o
