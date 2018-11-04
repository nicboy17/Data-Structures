
OPTIONS = -pedantic -Wall -Werror

test.o: test.c ListInterface.h ListType.h
	gcc $(OPTIONS) -c test.c

sort.o: sort.c ListInterface.h ListType.h
	gcc $(OPTIONS) -c sort.c

ListImplementation.o: ListImplementation.c ListInterface.h ListType.h
	gcc $(OPTIONS) -c ListImplementation.c

all: a.out sort.out
a.out: test.o ListImplementation.o
	gcc $(OPTIONS) test.o ListImplementation.o -o a.out

sort.out: sort.o ListImplementation.o
	gcc $(OPTIONS) sort.o ListImplementation.o -o sort.out

clean:
	rm *.o a.out
	rm *.o sort.out