SOURCES=test.cpp MidiModule.cpp DataBank/MappingScheme.cpp AlsaAdapter/AlsaAdapter.cpp DataBank/SensorConfiguration/SensorConfiguration.cpp

TARGET=MidiModuleTest
LIBRARIES=-lpthread

# Decide target
ifeq ($(ARCH), target)
	OBJDIR=target
	CXX=arm-angstrom-linux-gnueabi-g++
else

ifeq ($(DEBUG), y)
	CXXFLAGS=-O0 -g ${LIBRARIES}
else
	OBJDIR=debug
	CXX=g++
	CXXFLAGS=-O0 -g ${LIBRARIES}
endif
endif

OBJECTS=${addprefix ${OBJDIR}/,${SOURCES:.cpp=.o}}
DEPS=${addprefix ${OBJDIR}/,${SOURCES:.cpp=.d}}
EXECUTABLE=${OBJDIR}/${TARGET}

${OBJDIR}/%.d: %.cpp | ${OBJDIR}
	${CXX} -MT${@:.d=.o} -MM ${CXXFLAGS} $^ > $@

${OBJDIR}/%.o: %.cpp | ${OBJDIR}
	${CXX} -c -o $@ $^ ${CXXFLAGS}

.PHONY: all
all:  ${EXECUTABLE}	
${EXECUTABLE}: ${OBJECTS} ${DEPS}
	${CXX} -o $@ ${OBJECTS} ${CXXFLAGS}

${OBJDIR}:
	mkdir -p ${OBJDIR}

.PHONY: clean
clean: 
	rm -fr ${OBJDIR}
	
.PHONY: help
help:
	@echo "Make targets\n - ARCH\n  - debug(default)\n  - target\n - DEBUG\n  - no (default)\n  - yes\n - clean\n - help"
 
