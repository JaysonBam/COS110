#ifndef SIZEEXCEPTION_H
#define SIZEEXCEPTION_H

#include "ListException.h"

class SizeException: public ListException {
private:
    int m_size;

public:
    SizeException(int size); // Constructor
    std::string getError();
};

#endif