#Parameters
SOURCES=oppg2
CUSTOMBUILDS=
STDLIBS=

#Preferences
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
EXECUTABLES=$(SOURCES:%=%.exe)
CUSTOMEXECUTABLES=$(CUSTOMBUILDS:%=%.exe)

all: $(EXECUTABLES) $(CUSTOMEXECUTABLES)

%.exe: %.o $(STDLIBS:%=%.o)
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS) $<

clean:
	rm -f *.exe
	rm -f *.o