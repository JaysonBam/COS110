# List of object files
ofiles = main.o Node.o List.o SinglyLinked.o

# Compiler options
gpp_o = g++ -c -std=c++98

# Linker options
gpp = g++ -std=c++98

# Build the main program
main: $(ofiles)
	$(gpp) $(ofiles) -o main

# Compile main.cpp
main.o: main.cpp Node.h List.h SinglyLinked.h
	$(gpp_o) main.cpp

# Compile Node.cpp
Node.o: Node.cpp Node.h
	$(gpp_o) Node.cpp

# Compile List.cpp
List.o: List.cpp List.h Node.h
	$(gpp_o) List.cpp

# Compile SinglyList.cpp
SinglyLinked.o: SinglyLinked.cpp SinglyLinked.h List.h Node.h
	$(gpp_o) SinglyLinked.cpp

# Run the program
run: main
#	del -f *.o main
	./main

# Run valgrind for memory checking
valgrind: main
	valgrind --leak-check=full ./main


coverage: main
	g++ --coverage *.cpp -o main
	./main
	gcov -f -m -r -j main
# Clean the generated files
clean:
	del -f *.o main.exe
