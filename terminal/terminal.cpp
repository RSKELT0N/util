#include "terminal.h"

namespace util {

terminal::~terminal() {
    delete this->inst;
}

void terminal::print(std::initializer_list<const char*>& lst, const char* txt) const {
    
}

};