ofiles = main.o DataPoint.o DistanceFunction.o Algorithm.o
gpp_o = g++ -c -std=c++98 -g --coverage

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

main.o: main.cpp DataPoint.h DistanceFunction.h Algorithm.h
	$(gpp_o) main.cpp

DataPoint.o: DataPoint.cpp DataPoint.h
	$(gpp_o) DataPoint.cpp

DistanceFunction.o: DistanceFunction.cpp DistanceFunction.h
	$(gpp_o) DistanceFunction.cpp

Algorithm.o: Algorithm.cpp Algorithm.h DataPoint.h DistanceFunction.h
	$(gpp_o) Algorithm.cpp

run: main
	./main

debug: main
	gdb ./main

coverage: main
	./main
	gcov -f -m -r -j DataPoint Algorithm DistanceFunction

valgrind: main
	valgrind --leak-check=full ./main

clean:
	del -f *.o main.exe
	del -f *.gcda *.gcno *.gcov