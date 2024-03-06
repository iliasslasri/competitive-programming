## make and test

test: *.cpp
	g++ -Wall -Wextra -o main *.cpp
	./main < sample-C.1.in
	./main < sample-C.2.in
	cat sample-C.1.out
	cat sample-C.2.out
	