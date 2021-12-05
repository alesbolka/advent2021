build:
	@g++ -std=c++17 -o advent2021 src/main.cpp

day01-1:
	@make build --no-print-directory
	@./advent2021 1 1

day01-2:
	@make build --no-print-directory
	@./advent2021 1 2

day02-1:
	@make build --no-print-directory
	@./advent2021 2 1

day02-2:
	@make build --no-print-directory
	@./advent2021 2 2

day03-1:
	@make build --no-print-directory
	@./advent2021 3 1

day03-2:
	@make build --no-print-directory
	@./advent2021 3 2

day04-1:
	@make build --no-print-directory
	@./advent2021 4 1

day04-2:
	@make build --no-print-directory
	@./advent2021 4 2