#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"

#include <iostream>

template <typename T>
void printArray(const T* array, int size) {
    std::cout<<"[";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i];
        if (i < size - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

void print(Dictionary<std::string,int>& d) {
    std::string* names = d.getKeys();
    int size = d.size();
    printArray<std::string>(names,size);
    std::cout<<"[";
    for (int i = 0; i < size; ++i) {
        std::cout << d.at(names[i]);
        if (i < size - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

void test1(){
    Tuple<int,int> t1(1,2);
    Tuple<int,std::string> t2(1,"a");
    Tuple<int,std::string> t3(1,"a");
    Tuple<int,std::string> t4(2,"a");
    std::cout<<t2.getFirst()<<std::endl;
    std::cout<<t2.getSecond()<<std::endl; 
    if (t2 == t3)
        std::cout<<"t2 == t3"<<std::endl;
    else
        std::cout<<"t2 != t3"<<std::endl;  
    if (t3 == t4)
        std::cout<<"t3 == t4"<<std::endl;
    else
        std::cout<<"t3 != t4"<<std::endl;  
}

void test2(){
    Dictionary<std::string,int> dic;
    dic.set("Jack",54);
    print(dic);
    dic.set("John",98);
    print(dic);
    dic.set("Steve",32);
    print(dic);
    dic.set("John",43);
    print(dic);
    std::cout<<std::endl;

    std::cout<<"Jack:"<<dic.at("Jack")<<std::endl;
    std::cout<<"Jayson:"<<dic.at("Jayson")<<std::endl;
    std::cout<<std::endl;

    dic.set("Jayson",43);
    std::cout<<"Jack:"<<dic.exists("Jack")<<std::endl;
    std::cout<<"Jayson:"<<dic.exists("Jayson")<<std::endl;
    std::cout<<"Peter:"<<dic.exists("Peter")<<std::endl;
    std::cout<<std::endl;

    print(dic);
    Tuple<int,std::string*> t = dic.keysWithValue(43);
    printArray<std::string>(t.getSecond(),t.getFirst());
    delete[] t.getSecond();
    std::cout<<std::endl;

    print(dic);
    dic.swap("Jack","Steve");
    print(dic);
    std::cout<<std::endl;

    dic.removeAt("Jack");
    print(dic);
    dic.remove(43);
    print(dic);
    dic.removeAt("Jack");
    print(dic);
    dic.removeAt("Steve");
    print(dic);
    dic.removeAt("Jack");
    print(dic);
    dic.clear();
    dic.set("Jayson",43);
    dic.clear();
}

void test3(){
    ScoreBoard<int> s;
    std::cout<<"HS:"<<s.getHighScore()<<std::endl;
    std::cout<<"Jayson:"<<s.getScore("Jayson")<<std::endl;
    s.addScore("Jayson",4);
    std::cout<<"Jayson:"<<s.getScore("Jayson")<<std::endl;
    s.addScore("Jayson",2);
    std::cout<<"Jayson:"<<s.getScore("Jayson")<<std::endl;
    s.addScore("Jayson",5);
    std::cout<<"Jayson:"<<s.getScore("Jayson")<<std::endl;
    std::cout<<"HS:"<<s.getHighScore()<<std::endl;
    s.addScore("Peter",9);
    std::cout<<"HS:"<<s.getHighScore()<<std::endl;
    s.addScore("Jack",9);
    std::cout<<"HS:"<<s.getHighScore()<<std::endl;
    Tuple<int,std::string*> t = s.getHighScoreUser();
    printArray<std::string>(t.getSecond(),t.getFirst());
    delete[] t.getSecond();
}

int main(){
    test1();
    std::cout<<"===============================================\n";
    test2();
    std::cout<<"===============================================\n";
    test3();
    return 0;
}