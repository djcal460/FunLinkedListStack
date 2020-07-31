CC=gcc
CFLAGS=-I.
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

funfunlinkedliststack: funfunlinkedliststack.o menufunc.o func.o
	$(CC) -o funfunlinkedliststack funfunlinkedliststack.o menufunc.o func.o
clean:
	$(RM) funfunlinkedliststack.o menufunc.o func.o funfunlinkedliststack
