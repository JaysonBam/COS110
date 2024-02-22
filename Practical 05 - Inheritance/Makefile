# Define compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -g --coverage

# List of object files
OFILES = main.o Sword.o ShadowBone.o Soldier.o Mage.o Ninja.o Brute.o

# Main target
main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) -o main

# Dependencies and compilation rules
main.o: main.cpp Sword.h ShadowBone.h Soldier.h Mage.h Ninja.h Brute.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Sword.o: Sword.cpp Sword.h
	$(CXX) $(CXXFLAGS) -c Sword.cpp

ShadowBone.o: ShadowBone.cpp ShadowBone.h Sword.h
	$(CXX) $(CXXFLAGS) -c ShadowBone.cpp

Soldier.o: Soldier.cpp Soldier.h Sword.h
	$(CXX) $(CXXFLAGS) -c Soldier.cpp

Mage.o: Mage.cpp Mage.h Soldier.h ShadowBone.h
	$(CXX) $(CXXFLAGS) -c Mage.cpp

Ninja.o: Ninja.cpp Ninja.h Soldier.h
	$(CXX) $(CXXFLAGS) -c Ninja.cpp

Brute.o: Brute.cpp Brute.h Soldier.h
	$(CXX) $(CXXFLAGS) -c Brute.cpp

# Phony targets for running and cleaning
.PHONY: run coverage valgrind clean

run: main
	./main

coverage: main
	./main
	gcov -f -m -r -j Sword ShadowBone Soldier Mage Ninja Brute

valgrind: main
	valgrind --leak-check=full ./main

clean:
	del -f *.o main.exe
	del -f *.gcda *.gcno *.gcov
