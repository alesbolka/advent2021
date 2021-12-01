build:
	g++ -o advent2021 src/main.cpp

day01-1:
	make build --no-print-directory
	./advent2021 1 1