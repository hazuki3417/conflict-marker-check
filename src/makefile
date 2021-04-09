
build: build-classes
	@echo [run] $@;

	g++ -I ./classes -o ./conflict-marker-check ./*.o ./main.cpp
	make clean

	@echo;

build-classes:
	@echo [run] $@;

	g++ -I ./classes -c ./classes/*.cpp

	@echo;

clean:
	@echo [run] $@;

	rm -rfv ./*.o

	@echo;

test:
	@echo [run] $@;

	g++ -std=c++11 ./tests/ConflictTest.cpp -l gtest_main

	@echo;
