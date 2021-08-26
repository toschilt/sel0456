ALL = main

# $^ --> Todas as dependências
# $@ --> Nome do método

all: $(ALL)

main: main.c square.c
	gcc $(CFLAGS) $^ $(LDFLAGS) -o $@

run:
	./main

assembly:
	gcc -Os main.c -o main

clean:
	rm -f *.o *.s a.out

distclean: clean
	rm -r $(ALL)