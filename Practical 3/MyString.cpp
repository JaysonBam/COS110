#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "MyString.h" 

MyString::MyString(){
    mString = "";
}

bool ValidChar(char c) {
    int a = int(c);
    return (a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122);
}


std::string MyString::cleanString(std::string dirtyString){
    int size = dirtyString.length();
    std::string newLine = "";
    for (int i = 0; i < size; i++)
        if (ValidChar(dirtyString[i]))
            newLine += dirtyString[i];

    return newLine;
}

MyString::MyString(std::string instring){
    mString = cleanString(instring);
}

MyString::~MyString(){}

void MyString::print(){
    std::cout<<mString<<std::endl;
}

void MyString::clear(){
    mString = "";
}

bool MyString::operator<(const MyString& rhs) {
    if (*this == rhs)
        return false;

    int size = std::min(mString.length(), rhs.mString.length());

    for (int i = 0; i < size; i++) {
        if (std::tolower(mString[i]) < std::tolower(rhs.mString[i]))
            return true;
        else if (std::tolower(mString[i]) > std::tolower(rhs.mString[i]))
            return false;
    }

    return (mString.length() < rhs.mString.length());
}

bool MyString::operator==(const MyString& rhs) {
    if (mString.length() != rhs.mString.length())
        return false;

    for (int i = 0; i < mString.length(); i++) {
        if (std::tolower(mString[i]) != std::tolower(rhs.mString[i]))
            return false;
    }

    return true;
}

bool MyString::operator>(const MyString& rhs){
    if (*this == rhs || *this < rhs)
        return false;
    else
        return true;
}

bool MyString::operator!=(const MyString& rhs){
    return !(*this==rhs);
}

bool MyString::operator!(){
    return (mString.length() == 0);
}

std::string MyString::operator+(std::string rhs){
    return mString + cleanString(rhs);
}

std::string MyString::operator+(const MyString& rhs){
    return mString + rhs.mString;
}

MyString& MyString::operator+=(const MyString& rhs){
    mString += rhs.mString;
    return *this;
}

MyString& MyString::operator=(const std::string rhs){
    mString = cleanString(rhs);
    return *this;
}

MyString& MyString::operator=(const MyString& rhs){
    mString = rhs.mString;
    return *this;
}

MyString& MyString::operator=(std::fstream& file){
    if (!file.is_open()) 
        return *this;

    std::string fileContent;
    char ch;
    while (file.get(ch))
        fileContent += ch;

    file.close();

    mString = cleanString(fileContent);
    return *this;
}