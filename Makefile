CC = gcc
CCFLAGS = -O1 -Wall -I/usr/local/include -L/usr/local/lib

BUILDTARGET = bin/cpop
CHECKTARGET = bin/test

BUILDOBJECTS = bin/functions.o bin/mergesort.o
CHECKOBJECTS = bin/check_functions.o bin/check_mergesort.o

BUILDMAIN = bin/main.o
CHECKMAIN = bin/check_all.o

HEADERS = src/*.h

build: $(BUILDTARGET)

check: $(CHECKTARGET)
	@ $(CHECKTARGET)

$(BUILDTARGET): clean $(BUILDOBJECTS) $(BUILDMAIN) $(HEADERS)
	@ $(CC) $(CCFLAGS) bin/*.o -o $(BUILDTARGET)

$(CHECKTARGET): clean $(BUILDOBJECTS) $(CHECKOBJECTS) $(CHECKMAIN) $(HEADERS)
	@ $(CC) $(CCFLAGS) bin/*.o -o $(CHECKTARGET) -l check

bin/%.o: src/%.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

bin/%.o: spec/%.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@ rm -f bin/*
