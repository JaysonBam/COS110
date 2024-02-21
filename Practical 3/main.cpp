#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "MyString.h" 

std::string getComparison(MyString mstr1, MyString mstr2) {
    if (mstr1 == mstr2) return " == ";
    if (mstr1 < mstr2) return " < ";
    if (mstr1 > mstr2) return " > ";
    return " Error ";
}


int main() {
    MyString* C1 = new MyString;
    MyString* C2 = new MyString;

    std::string S1[] = {"a", "A", "A", "a", "0", "1", "9", "aa", "aa", "aba", "aBa", "aBa", "b", "a92bazzz", "a", "01a", "z", "abcu", "K", "K30", "zoey", "metric"};
    std::string S2[] = {"b", "b", "B", "A", "1", "9", "a", "aa", "aaa", "abaa", "AbA", "abaa", "abbb", "a93bR", "a", "01A", "yaj", "abce", "z30", "z", "abigal", "imperial"};

    for (int i = 0; i < 22; i++) {
        *C1 = S1[i];
        *C2 = S2[i];
        std::cout << S1[i] << getComparison(*C1, *C2) << S2[i] << std::endl;
    }   

    // Test constructors and operator=
    MyString* str1 = new MyString("Hello");
    MyString* str2 = new MyString(std::string(" World"));
    MyString* str3 = new MyString;

    // Test operator+ and operator+=
    MyString* combined = new MyString(*str1 + *str2);
    *str1 += *str2;

    // Test comparison operators
    bool isEqual = (*str1 == *combined);
    bool isNotEqual = (*str1 != *str3);
    bool isLessThan = (*str1 < *combined);
    bool isGreaterThan = (*combined > *str2);

    // Test cleanString
    std::string dirty = "aBC % $k$48J f {} d 1\n2";

    // Test print
    std::cout << "Combined: ";
    combined->print();
    std::cout << std::endl;

    // Test operator= with string and file
    MyString* str4 = new MyString;
    *str4 = "Assignment";
    *str4 = *str1;
    std::fstream myfile("test.txt");
    *str4 = myfile;
    str4->print();

    // Test clear and operator!
    str4->clear();
    bool isEmpty = !(*str4);

    // Output results
    std::cout << "Is Equal: " << isEqual << std::endl;
    std::cout << "Is Not Equal: " << isNotEqual << std::endl;
    std::cout << "Is Less Than: " << isLessThan << std::endl;
    std::cout << "Is Greater Than: " << isGreaterThan << std::endl;
    std::cout << "String after Clear: ";
    str4->print();
    std::cout << std::endl;
    std::cout << "Is Empty: " << isEmpty << std::endl;

    // Clean up dynamically allocated objects
    delete C1;
    delete C2;
    delete str1;
    delete str2;
    delete str3;
    delete combined;
    delete str4;

    return 0;
}
