SOURCES=main.cpp BTRock.cpp MsgQueue.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=BTRockTest
CXX=g++
FLAGS=-g
LIBRARIES=-lpthread


%.o: %.cpp
	${CXX} -c -o $@ $^ ${FLAGS}

${EXECUTABLE}: ${OBJECTS}
	${CXX} -o $@ $^ ${FLAGS} ${LIBRARIES}
	
clean:
	rm ${EXECUTABLE} ${OBJECTS}

help:
	echo "\nAvailable targets:\nclean\nhelp\n"