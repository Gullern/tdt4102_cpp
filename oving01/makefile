#Parameters
SOURCES=oppg1 oppg2 oppg3 oppg4 oppg5 oppg6
CUSTOMBUILDS=menu
STDLIBS=ui

#Preferences
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
EXECUTABLES=$(SOURCES:%=%.exe)
CUSTOMEXECUTABLES=$(CUSTOMBUILDS:%=%.exe)

all: $(EXECUTABLES) $(CUSTOMEXECUTABLES)

%.exe: %.o $(STDLIBS:%=%.o)
	$(CC) -o $@ $(LDFLAGS) $^

menu.exe: oppg2_m.o oppg3_m.o oppg4_m.o oppg5_m.o oppg6_m.o $(STDLIBS:%=%.o)
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS) $<

%_m.o: %.cpp %.h
	$(CC) -o $@ $(CFLAGS) $< -DMENU

clean:
	rm -f *.exe
	rm -f *.o