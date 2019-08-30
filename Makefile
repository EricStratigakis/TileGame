CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q2a
OBJECTS = main.o subject.o grid.o textdisplay.o cell.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
