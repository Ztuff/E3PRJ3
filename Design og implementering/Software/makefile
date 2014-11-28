SRCS=controller.cpp
OBJS=$(SRCS:.cpp=.o)
BASEPATH=..
# Determine whether this is a debug build or not
ifdef DEBUG
CXXFLAGS=-ggdb -O0
LIBPATH=$(BASEPATH)/lib/host/debug
else
CXXFLAGS=-O2
LIBPATH=$(BASEPATH)/lib/host/release
endif
# Setup the CFLAGS to ensure that the relevant warnings, includes and defines.
CXXFLAGS+=-Wall -D_REENTRANT -DOS_LINUX -I$(BASEPATH)/inc

main: $(OBJS)
	g++ -o PLCS $(OBJS)  -L$(LIBPATH) -lOSApi -lrt -lpthread

all: main

clean:
	rm -f *.o main
