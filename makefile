main: main.o mixed.o mixed.h control.h control.o Polynomial.h Polynomial.o
	g++ -g main.o mixed.o mixed.h control.h control.o Polynomial.h Polynomial.o -o main

main.o: main.cpp
	g++ -g -c main.cpp -o main.o

mixed.o: mixed.cpp
	g++ -g -c mixed.cpp -o mixed.o

control.o: control.cpp
	g++ -g -c control.cpp -o control.o

Polynomial.o: Polynomial.cpp
	g++ -g -c Polynomial.cpp -o Polynomial.o

clean:
	rm *.o
	rm main
