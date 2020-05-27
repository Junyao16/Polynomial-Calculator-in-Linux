main: main.o input_polynomial.o input_polynomial.h deal_with_input.o deal_with_input.h control.h control.o Polynomial.h Polynomial.o
	g++ -g main.o input_polynomial.o input_polynomial.h deal_with_input.o deal_with_input.h control.h control.o Polynomial.h Polynomial.o -o main

main.o: main.cpp
	g++ -g -c main.cpp -o main.o

input_polynomial.o: input_polynomial.cpp
	g++ -g -c input_polynomial.cpp -o input_polynomial.o

deal_with_input.o: deal_with_input.cpp
	g++ -g -c deal_with_input.cpp -o deal_with_input.o

control.o: control.cpp
	g++ -g -c control.cpp -o control.o

Polynomial.o: Polynomial.cpp
	g++ -g -c Polynomial.cpp -o Polynomial.o

clean:
	rm *.o
	rm main
