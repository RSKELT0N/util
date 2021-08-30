#include "terminal.h"

namespace util {

terminal* terminal::inst = nullptr;

terminal::~terminal() {
     delete inst;
}

terminal* terminal::get_instance() {
    if(inst == nullptr)
        inst = static_cast<terminal*>(malloc(sizeof(terminal)));
    
    return inst;
}

std::string terminal::_format(const char* ansii) const {
    std::string rs = PREFIX;
    rs += ansii;
    rs += SUFFIX;

    return rs;
}

void terminal::_action(const char* ansii) {
    std::cout << _format(ansii) << "\n";
}

void terminal::_print(const char* txt, const char* ansii, ...) const {
    va_list lst;
    std::string rs;

    va_start(lst, ansii);
    while(*ansii != '\0') {
        rs += std::string(ansii) + ";";
        ansii++;
    }
    va_end(lst);
    rs[rs.size()-1] = '\0';
    printf("%s%s\n", _format(rs.c_str()).c_str(), txt);
}

};