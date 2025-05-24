
all: clean test

programtest: tests.cpp graph.cpp
	g++ -fsanitize=address -std=c++11 tests.cpp graph.cpp -o programtest

test: programtest
	./programtest

clean:
	rm -f programtest a.out a.exe