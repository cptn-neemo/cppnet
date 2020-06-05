CXX = g++
LIB = ./src/build/cppnet.a

demo: demo.cpp ${LIB}
	cd src && make && cd ..
	${CXX} -o demo demo.cpp ${LIB}

clean: demo
	-rm demo
