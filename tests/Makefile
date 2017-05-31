.PHONY: test
test: 
	g++ -std=c++11 -I include -c -o build/main.o tests/main.cpp
	g++ -std=c++11 -I include -c -o build/foo1.o tests/foo1.cpp
	g++ -std=c++11 -I include -c -o build/foo2.o tests/foo2.cpp
	g++ -std=c++11 -o build/tests build/foo1.o build/foo2.o build/main.o
	build/tests
