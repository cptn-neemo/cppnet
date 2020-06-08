CC = g++
LIB = ./build/cppnet.a

SRC = $(wildcard ./*/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

lib: $(OBJS)

%.o: %.cpp
	$(CC) -o $@ -c $^
	@ar rvs $(LIB) $@

clean:
	@rm -f */*.o
