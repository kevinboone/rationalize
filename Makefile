PREFIX=/usr
DESTDIR=/
TARGET=rationalize
VERSION=0.1a

CFLAGS=-Wall -Wextra 
LDFLAGS=-s

all: $(TARGET) 

$(TARGET): rationalize.c main.c rationalize.h
	gcc $(CFLAGS) $(LDFLAGS) -o $(TARGET) -DVERSION=\"$(VERSION)\" rationalize.c main.c -lm

install:
	install -m 755 $(TARGET) $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -f $(TARGET) *.o

