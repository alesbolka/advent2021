build:
	@g++-10 -std=c++20 -o advent2021 src/main.cpp

prepare:
	@mkdir "src/day${day}"
	@touch "src/day${day}/input.txt"
	@touch "src/day${day}/sample.txt"
	@touch "src/day${day}/day${day}.cpp"
	@cp src/shared/sample.cpp "src/day${day}/day${day}.cpp"
	@cp src/shared/sample.h "src/day${day}/day${day}.h"
	@sed -i 's/XX/${day}/' "src/day${day}/day${day}.h"
	@sed -i 's/XX/${day}/' "src/day${day}/day${day}.cpp"
	@echo "Prepared day ${day} files"
