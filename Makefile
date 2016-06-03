CC=g++
CFLAGS=-c -Wall -g
LDFLAGS= -g
SOURCES= \
        main.cpp \
				lab.cpp \
				ArkunovIL.cpp \
				cheboksarovv.cpp \
				Chucmarevaki.cpp \
				godyaev.cpp \
				karchiganovaf.cpp \
				lamaikinai.cpp \
				labushkinamn.cpp \
				Levshtanoviv.cpp \
				Lysov.cpp \
				morozovns.cpp \
				nazarovvi.cpp \
				novikovdv.cpp	\
				ploduhindm.cpp \
				PolkinAV.cpp \
				PolyaevaEV.cpp \
				sadovnikovev.cpp \
				Salnikov.cpp \
				Samylkin.cpp \
				Suharev.cpp \
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
