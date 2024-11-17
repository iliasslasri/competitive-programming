all: 1.cc
	g++ -g -O2 -Wall -Wextra -o main -std=gnu++23 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive 6.cc
	./main < 1.in
