# List of object files
ofiles = main.o accessory.o car.o engine.o

# Compiler and compiler flags
gpp_o = g++ -c -std=c++98 -g --coverage

# Linker and linker flags
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

# Build rules for each object file
main.o: main.cpp accessory.h car.h engine.h
	$(gpp_o) main.cpp

accessory.o: accessory.cpp accessory.h
	$(gpp_o) accessory.cpp

car.o: car.cpp accessory.h car.h engine.h
	$(gpp_o) car.cpp

engine.o: engine.cpp engine.h
	$(gpp_o) engine.cpp

# Run the program
run: main
	./main

# Debug using gdb
debug: main
	gdb ./main

# Generate coverage reports
coverage: main
	./main
	gcov -f -m -r -j accessory car engine

# Run valgrind for memory checking
valgrind: main
	valgrind --leak-check=full ./main

# Clean up generated files
clean:
	rm -f *.o main.exe
	rm -f *.gcda *.gcno *.gcov
