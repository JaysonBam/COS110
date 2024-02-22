ofiles = main.o ListException.o ConstructorException.o IndexException.o SizeException.o ArrayWrap.o
gpp_o = g++ -c -std=c++98 -g --coverage

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

main.o: main.cpp ListException.h ConstructorException.h IndexException.h SizeException.h ArrayWrap.h
	$(gpp_o) main.cpp

ListException.o: ListException.cpp ListException.h
	$(gpp_o) ListException.cpp

ConstructorException.o: ConstructorException.cpp ConstructorException.h ListException.h
	$(gpp_o) ConstructorException.cpp

IndexException.o: IndexException.cpp IndexException.h ListException.h
	$(gpp_o) IndexException.cpp

SizeException.o: SizeException.cpp SizeException.h ListException.h
	$(gpp_o) SizeException.cpp

ArrayWrap.o: ArrayWrap.cpp ListException.h ConstructorException.h IndexException.h SizeException.h
	$(gpp_o) ArrayWrap.cpp

run: main
	./main
	del rm *.o main.exe
	del -f *.gcda *.gcno *.gcov

clean: 
	del rm *.o main.exe
	del -f *.gcda *.gcno *.gcov