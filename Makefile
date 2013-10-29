CC = gcc
CCFLAGS = -O1 -Wall -I/usr/local/include -L/usr/local/lib

BUILDLINKNM = closest-pair
BUILDTARGET = bin/closest-pair
CHECKTARGET = bin/test

BUILDOBJECTS = bin/mergesort.o bin/compare.o bin/closest.o
CHECKOBJECTS = bin/check_mergesort.o bin/check_closest.o

BUILDMAIN = bin/main.o
CHECKMAIN = bin/check_all.o

ONLYHEADERS = src/types.h

build: $(BUILDTARGET)
	@ ln -s $(BUILDTARGET) $(BUILDLINKNM)

check: $(CHECKTARGET)
	@ $(CHECKTARGET)

$(BUILDTARGET): clean $(BUILDOBJECTS) $(BUILDMAIN) $(ONLYHEADERS)
	@ $(CC) $(CCFLAGS) bin/*.o -o $(BUILDTARGET)

$(CHECKTARGET): clean $(BUILDOBJECTS) $(CHECKOBJECTS) $(CHECKMAIN) $(ONLYHEADERS)
	@ $(CC) $(CCFLAGS) bin/*.o -o $(CHECKTARGET) -l check

bin/%.o: src/%.c src/%.h
	@ $(CC) $(CCFLAGS) -c $< -o $@

bin/%.o: spec/%.c spec/%.h
	@ $(CC) $(CCFLAGS) -c $< -o $@

bin/%.o: src/%.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

bin/%.o: spec/%.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@ rm -f bin/*
	@ rm -f $(BUILDLINKNM)
