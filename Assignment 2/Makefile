# Define the source files and object files
sources = main.cpp term.cpp polynomial.cpp univariate.cpp linear.cpp quadratic.cpp circle.cpp bivariate.cpp ellipse.cpp
ofiles = $(sources:.cpp=.o)

# Compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++98 -g --coverage

# Targets
main: $(ofiles)
	$(CXX) $(CXXFLAGS) $(ofiles) -o main

main.o: main.cpp term.h polynomial.h univariate.h linear.h quadratic.h bivariate.h circle.h ellipse.h
	$(CXX) $(CXXFLAGS) -c main.cpp

term.o: term.cpp term.h
	$(CXX) $(CXXFLAGS) -c term.cpp

polynomial.o: polynomial.cpp polynomial.h 
	$(CXX) $(CXXFLAGS) -c polynomial.cpp

univariate.o: univariate.cpp univariate.h
	$(CXX) $(CXXFLAGS) -c univariate.cpp

linear.o: linear.cpp linear.h
	$(CXX) $(CXXFLAGS) -c linear.cpp

quadratic.o: quadratic.cpp quadratic.h
	$(CXX) $(CXXFLAGS) -c quadratic.cpp

bivariate.o: bivariate.cpp bivariate.h
	$(CXX) $(CXXFLAGS) -c bivariate.cpp

circle.o: circle.cpp circle.h
	$(CXX) $(CXXFLAGS) -c circle.cpp

ellipse.o: ellipse.cpp ellipse.h
	$(CXX) $(CXXFLAGS) -c ellipse.cpp

run: main
	./main

coverage: main
	./main
	gcov -f -m -r -j term polynomial univariate linear quadratic bivariate circle ellipse

valgrind: main
	valgrind --leak-check=full ./main

clean:
	del -f *.o main.exe *.gcda *.gcno *.gcov *.gz
