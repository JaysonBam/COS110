# List of object files
ofiles = main.o List.o CLinkedList.o Stack.o Queue.o

# Compiler options
gpp_o = g++ -c -std=c++98

# Linker options
gpp = g++ -std=c++98

# Build the main program
main: $(ofiles)
	$(gpp) $(ofiles) -o main

# Compile main.cpp
main.o: main.cpp Node.h List.h CLinkedList.h Stack.h Queue.h
	$(gpp_o) main.cpp

# Compile List.cpp
List.o: List.cpp List.h Node.h
	$(gpp_o) List.cpp

# Compile CLinkedList.cpp
CLinkedList.o: CLinkedList.cpp CLinkedList.h List.h Node.h
	$(gpp_o) CLinkedList.cpp

# Compile Stack.cpp
Stack.o: Stack.cpp Stack.h Node.h
	$(gpp_o) Stack.cpp

# Compile Queue.cpp
Queue.o: Queue.cpp Queue.h Node.h
	$(gpp_o) Queue.cpp

# Run the program
run: main
	./main

# Memory leak checking with Valgrind
valgrind: main
	valgrind --leak-check=full ./main

# Code coverage with gcov
coverage: main
	g++ --coverage *.cpp -o main
	./main
	gcov -f -m -r -o . main.cpp
	rm -f main.gcda main.gcno

# Clean the project
clean:
	del -f *.o main.exe
