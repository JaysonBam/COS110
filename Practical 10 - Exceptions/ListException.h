#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

#include <string>

class ListException {
public:
    virtual std::string getError();
};

#endif // LISTEXCEPTION_H