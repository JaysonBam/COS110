#include "ListException.h"
#include "ConstructorException.h"
#include "IndexException.h"
#include "SizeException.h"
#include "ArrayWrap.h"
#include <iostream>

int main(){
    std::cout<<"Hello world\n";
    ListException e1;
    std::cout<<e1.getError()<<std::endl;
    ConstructorException e2;
    std::cout<<e2.getError()<<std::endl;
    IndexException e3(5,3);
    std::cout<<e3.getError()<<std::endl;
    SizeException e4(5);
    std::cout<<e4.getError()<<std::endl;

    try{
        ArrayWrap<int> arr(5);

        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);

        std::cout << "Array contents: ";
        arr.print();

        std::cout << "Popping: " << arr.pop_back() << std::endl;
        std::cout << "Popping: " << arr.pop_back() << std::endl;

        std::cout << "Array contents after popping: ";
        arr.print();

        arr.push_back(9);
        arr.push_back(7);
        arr.swap(0, 1);
        std::cout << "Array contents after swapping: ";
        arr.print();

        std::cout << "Array contents after removing element at index 0["<<arr[0]<<"]: ";
        arr.remove(0);
        arr.print();

        arr.clear();
        std::cout << "Array contents after clearing: ";
        arr.print();
    }
    catch(ListException &e){
        std::cout<<e.getError()<<std::endl;
    }
    
    return 0;
}