CC = gcc
CFLAGS = -Wall -g

TARGETS = fileio commandlineargs calc-average-grades

all: $(TARGETS)

fileio: fileio.c
	$(CC) $(CFLAGS) -o $@ $<

commandlineargs: commandlineargs.c
	$(CC) $(CFLAGS) -o $@ $<

calc-average-grades: calc-average-grades.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(TARGETS)
