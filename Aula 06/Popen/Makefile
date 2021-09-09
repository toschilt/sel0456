DEFFLAGS = $(patsubst %, -D%, OPTION1 OPTION2 OPTION3)

CFLAGS = -O2 -g $(DEFFLAGS)
LDFLAGS = -lm -lpthread
GCC = gcc

ALL = popen gnuplot popen-read

all: $(ALL)

popen: popen.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

popen-read: popen-read.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

gnuplot: gnuplot.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

%.s: %.c
	$(GCC) $(CFLAGS) -S $<

clean:
	rm -f *.o *.s a.out

distclean: clean
	rm -r $(ALL)