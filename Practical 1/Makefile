ofiles = main.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

clean:
	del *.o main.exe