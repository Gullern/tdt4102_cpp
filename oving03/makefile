#Parameters
SOURCES=main
CUSTOMBUILDS=
STDLIBS=utilities tests mastermind

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

%_m.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS) $< -DMENU

clean:
	rm -f *.exe
	rm -f *.o