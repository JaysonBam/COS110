ofiles = main.o warehouse.o crate.o 
gpp_o = g++ -c -std=c++98 -g --coverage

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

main.o: main.cpp warehouse.h crate.h 
	$(gpp_o) main.cpp

warehouse.o: warehouse.cpp warehouse.h
	$(gpp_o) warehouse.cpp

crate.o: crate.cpp crate.h
	$(gpp_o) crate.cpp

run: main
	./main

coverage: main
	./main
	gcov -f -m -r -j warehouse crate 

valgrind: main
	valgrind --leak-check=full ./main

clean:
	del -f *.o main.exe
	del -f *.gcda *.gcno *.gcov