#include "terminal.h"

namespace util {

terminal* terminal::inst = nullptr;

terminal::~terminal() {
     delete inst;
}

terminal* terminal::get_instance() {
    if(!terminal::inst)
        terminal::inst = static_cast<terminal*>(malloc(sizeof(terminal)));
    
    return terminal::inst;
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
    //defining variadic list
    va_list lst;
    //defining return
    std::string rs;

    //adding ansii into one std::string instance, 'rs'.
    va_start(lst, ansii);
    //checking if last char/char->* till '/0' is null
    while(std::regex_match(ansii, std::regex("^[a-zA-Z0-9]+$"))) {
        rs += std::string(ansii) + ";";
        //jumping to next variable argument in lst.
        ansii = va_arg(lst, const char*);

        if(!ansii)
            ansii = "!";
    }
    va_end(lst);

    //removing ending ';'
    rs[rs.size()-1] = '\0';
    //printing text in ansii format
    rs = _format(rs.c_str());
    std::cout << rs << txt << "\n";
}

};