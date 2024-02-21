#include "IndexException.h"
#include <sstream>

IndexException::IndexException(int index, int size) : m_index(index), m_size(size) {}

std::string IndexException::getError() {
    std::stringstream ss1;
    ss1 << m_index;
    std::string s_index;
    ss1 >> s_index;
    
    std::stringstream ss2;
    ss2 << m_size;
    std::string s_size;
    ss2 >> s_size;

    if (m_index < 0)
        return "Index " + s_index + " is negative.";
    else
        return "Index " + s_index + " is out of bounds for list of size " + s_size + ".";
}
