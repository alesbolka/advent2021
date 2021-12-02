build:
	@g++ -std=c++17 -o advent2021 src/main.cpp

day01-1:
	@make build --no-print-directory
	@./advent2021 1 1

day01-2:
	@make build --no-print-directory
	@./advent2021 1 2