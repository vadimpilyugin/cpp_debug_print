.PHONY: all
all: build/printer

build/printer.o: src/printer.cpp include/printer.h
	

build/printer: src/main.cpp include/printer.h
	clear; clear; mkdir -p build;
	g++ -std=c++11 -o build/printer -I include/ src/main.cpp

.PHONY: test
test: all
	./build/printer Hello World Lorem Ipsum SampleText
	make --makefile=tests/Makefile test
