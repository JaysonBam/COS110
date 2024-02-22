# List of object files
ofiles = main.o MyString.o

# Compiler and compiler flags
gpp_o = g++ -c -std=c++98 -g --coverage

# Linker and linker flags
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

# Build rules for each object file
main.o: main.cpp MyString.h
	$(gpp_o) main.cpp

MyString.o: MyString.cpp MyString.h
	$(gpp_o) MyString.cpp

# Run the program
run: main
	./main

# Debug using gdb
debug: main
	gdb ./main

# Generate coverage reports
coverage: main
	./main
	gcov -f -m -r -j MyString

# Run valgrind for memory checking
valgrind: main
	valgrind --leak-check=full ./main

# Clean up generated files
clean:
	del -f *.o main.exe
	del -f *.gcda *.gcno *.gcov