SOURCES=soundTest.cpp MidiModule/MidiModule.cpp MidiModule/DataBank/MappingScheme.cpp MidiModule/AlsaAdapter/AlsaAdapter.cpp MidiModule/DataBank/SensorConfiguration.cpp BT/Receiver.cpp

SUBDIRS=MidiModule BT MidiModule/DataBank MidiModule/AlsaAdapter
TARGET=soundTest
LIBRARIES=-lpthread -lasound

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
FULLSUBDIRS=${addprefix ${OBJDIR}/,${SUBDIRS}}


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
	mkdir -p ${FULLSUBDIRS}

.PHONY: clean
clean: 
	rm -fr ${OBJDIR}
	
.PHONY: help
help:
	@echo "Make targets\n - ARCH\n  - debug(default)\n  - target\n - DEBUG\n  - no (default)\n  - yes\n - clean\n - help"
 
