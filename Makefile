CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = SmashTest
OBJECTS = main.o player.o controller.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.Phony: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}