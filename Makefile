CC=g++
CFLAGS=-c -Wall -g
LDFLAGS= -g
SOURCES= \
        main.cpp \
				lab.cpp \
				cheboksarovv.cpp \
				karchiganovaf.cpp \
				Levshtanoviv.cpp \
				Lysov.cpp \
				morozovns.cpp \
				nazarovvi.cpp \
				ploduhindm.cpp \
				PolyaevaEV.cpp \
				Salnikov.cpp \
				Samylkin.cpp \
				Sukhova.cpp \
				timovkin.cpp \
				Zelyunko.cpp


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=vvm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o vvm
