CXX = g++

demo: demo.cpp Packet.o Header.o cppnet.h
	${CXX} -o demo demo.cpp Packet.o Header.o 

Packet.o: Packet.h Packet.cpp
	${CXX} -c Packet.h Packet.cpp

Header.o: Header.h Header.cpp
	${CXX} -c Header.h Header.cpp
clean:
	-rm -f *.o
	-rm demo
