#ifndef MYSTRING_H
#define MYSTRING_H

//#include <fstream>
//#include <sstream>
//#include <stdlib.h>

class MyString {
private:
    std::string mString;
    std::string cleanString(std::string dirtyString); 
public:
    MyString();
    MyString(std::string instring);
    ~MyString();
    void print();
    void clear();
    bool operator<(const MyString& rhs);
    bool operator>(const MyString& rhs);
    bool operator==(const MyString& rhs);
    bool operator!=(const MyString& rhs);
    bool operator!();
    std::string operator+(std::string rhs);
    std::string operator+(const MyString& rhs);
    MyString& operator+=(const MyString& rhs);
    MyString& operator=(const std::string rhs);
    MyString& operator=(const MyString& rhs);
    MyString& operator=(std::fstream& rhs);      
};

#endif // ACCESSORY_H