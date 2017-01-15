all: build run print

build: sources/main.cpp
	g++ sources/main.cpp -o result/main

run: result/main
	result/main > result/output.txt

print: result/output.txt
	cat result/output.txt
