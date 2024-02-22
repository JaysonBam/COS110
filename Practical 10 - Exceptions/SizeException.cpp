#include "SizeException.h"
#include <sstream>

SizeException::SizeException(int size) : m_size(size) {}

std::string SizeException::getError() {
    if (m_size == 0)
        return "List is empty.";
    else{
        std::stringstream ss;
        ss << m_size;
        std::string s_size;
        ss >> s_size;
        return "List is full with " + s_size + " elements.";
    }
}
