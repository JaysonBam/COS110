ofiles = main.o Tuple.o ScoreBoard.o Dictionary.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Tuple.h ScoreBoard.h Dictionary.h
	$(gpp_o) main.cpp

Tuple.o: Tuple.cpp
	$(gpp_o) Tuple.cpp

Dictionary.o: Dictionary.cpp Tuple.h
	$(gpp_o) Dictionary.cpp

ScoreBoard.o: ScoreBoard.cpp Dictionary.h Tuple.h
	$(gpp_o) ScoreBoard.cpp

run: main
	./main

valgrind: main
	valgrind --leak-check=full ./main

clean:
	rm *.o main
