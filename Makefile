all: challenge-optimisation-2023


CC = gcc
WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2


challenge-optimisation-2023: Makefile src/main.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) src/main.c

clean:
	rm -f pse-billeterie-client

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./challenge-optimisation-2023
