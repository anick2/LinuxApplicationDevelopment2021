GENERATES = prog prog-a prog-so README
TRASH = *.txt *.o *~ o.* *.a *.so
CFLAGS=-fPIC

all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@

prog-so:    prog.o liboutput.so
	cc -L. $< -loutput -o $@

liboutput_static.a: const.o fun.o
	ar -rcs $@ $^

liboutput.so:   fun.o const.o
	cc -shared $^ -o $@

README: prog
	./$< 2> $@

fun.o:  outlib.h

test:   prog prog-a prog-so
	./prog > test_1.txt
	./prog-a > test_2.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so > test_3.txt
	diff test_1.txt test_2.txt
	diff test_1.txt test_3.txt
	diff test_2.txt test_3.txt

	./prog hello > test_1.txt
	./prog-a hello > test_2.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so hello > test_3.txt
	diff test_1.txt test_2.txt
	diff test_1.txt test_3.txt
	diff test_2.txt test_3.txt

	./prog hello world endline > test_1.txt
	./prog-a hello world endline > test_2.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so hello world endline > test_3.txt
	diff test_1.txt test_2.txt
	diff test_1.txt test_3.txt
	diff test_2.txt test_3.txt

clean:
	rm -f $(TRASH)

distclean:  clean
	rm -f $(GENERATES)
