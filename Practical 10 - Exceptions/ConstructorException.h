#ifndef CONSTRUCTOREXCEPTION_H
#define CONSTRUCTOREXCEPTION_H

#include "ListException.h"

class ConstructorException:public ListException{
    public: 
        std::string getError();
};

#endif //CONSTRUCTOREXCEPTION_H