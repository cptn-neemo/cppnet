CC = g++
LIB = ./build/cppnet.a

SRC = $(wildcard ./*/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRC))

# main : $(OBJS) $(CPP_FILES) dog
#	@echo $(CPP_FILES)
#	@echo $(OBJS)

lib: $(OBJS)

%.o: %.cpp
	$(CC) -o $@ -c $^
	ar rvs $(LIB) $@

clean:
	@rm -f */*.o
