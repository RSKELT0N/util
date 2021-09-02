#include "terminal.h"

terminal* terminal::m_inst = nullptr;

terminal::~terminal() {
     delete m_inst;
}

terminal* terminal::get_instance() {
    if(!terminal::m_inst)
        terminal::m_inst = static_cast<terminal*>(malloc(sizeof(terminal)));
    
    return terminal::m_inst;
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
    std::string rs;

    //adding ansii into one std::string instance, 'rs'.
    va_start(lst, ansii);
    //checking if last char/char->* till '/0' is null
    while(std::regex_match(ansii, std::regex(GRAPHIC_REGEX))) {
        //jumping to next variable argument in lst.
        rs += std::string(ansii);
        ansii = va_arg(lst, const char*);

        //checking if ansii is null, if so, 
        //append anything so seg fault doesn't occur
        if(!ansii)
            ansii = "!";
    }
    va_end(lst);

    //removing ending ';'
    rs[rs.size()-1] = '\0';
    //printing text in ansii format
    rs = _format(rs.c_str());
    printf("%s%s", rs.c_str(), txt);
}