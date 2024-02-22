# Define object files
ofiles = main.o item.o product.o service.o bulk.o discountedProduct.o labor.o subscription.o shop.o

# Define compiler flags
gpp_o = g++ -c -std=c++98 -g --coverage

# Define the main target
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main --coverage

# Define rules to compile source files into object files
main.o: main.cpp item.h product.h service.h bulk.h discountedProduct.h labor.h subscription.h shop.h
	$(gpp_o) main.cpp

item.o: item.cpp item.h
	$(gpp_o) item.cpp

product.o: product.cpp product.h item.h
	$(gpp_o) product.cpp

service.o: service.cpp service.h item.h
	$(gpp_o) service.cpp

bulk.o: bulk.cpp bulk.h product.h item.h
	$(gpp_o) bulk.cpp

discountedProduct.o: discountedProduct.cpp discountedProduct.h product.h item.h
	$(gpp_o) discountedProduct.cpp

labor.o: labor.cpp labor.h service.h item.h
	$(gpp_o) labor.cpp

subscription.o: subscription.cpp subscription.h service.h item.h
	$(gpp_o) subscription.cpp

shop.o: shop.cpp shop.h item.h
	$(gpp_o) shop.cpp

# Define run target
run: main
	./main
#	del -f *.o main.exe
#	del -f *.gcda *.gcno *.gcov

# Define coverage target
coverage: main
	./main
	gcov -f -m -r -j item product service bulk discountedProduct labor subscription shop

# Define valgrind target
valgrind: main
	valgrind --leak-check=full ./main

# Define clean target
clean:
	del -f *.o main.exe
	del -f *.gcda *.gcno *.gcov