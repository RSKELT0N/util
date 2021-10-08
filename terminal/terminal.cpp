#include "terminal.h"

 terminal util::terminal::m_inst;

terminal* terminal::get_instance() {
    return &m_inst;
}

std::string terminal::_format(const char* ansii) const {
    std::string rs = PREFIX;
    rs += ansii;

    if(std::regex_match(ansii, GRAPHIC_REGEX))
        rs += SUFFIX;

    return rs;
}

void terminal::_get_cursor() const {
}

void terminal::_set_cursor(const uint8_t& row, const uint8_t& col) const {
    action(control::CURSOR_HOME);
    action(bindd(control::CURSOR_DOWN_N, row));
    action(bindd(control::CURSOR_RIGHT_N, col));
}

void terminal::_set(const char* ansii, ...) const {
    va_list lst;
    std::string rs;

    va_start(lst, ansii);

    while(std::regex_match(ansii, GRAPHIC_REGEX)) {
        rs += std::string(ansii);
        ansii = va_arg(lst, const char*);

        if(!ansii)
            ansii = "!";
    }

    rs[rs.size()-1] = '\0';
    rs = _format(rs.c_str());
    printf("%s", rs.c_str());
}

/**
 * @brief used for control ansii escxape characters 
 * @param ansii code inserted into function to control terminal
 */
void terminal::_action(const char* ansii) {
    std::string rs = _format(ansii);
    printf("%s", rs.c_str());
}

void terminal::_print(const char* txt, const char* ansii, ...) const {
    va_list lst;
    std::string rs;

    va_start(lst, ansii);
    while(std::regex_match(ansii, GRAPHIC_REGEX)) {
        rs += std::string(ansii);
        ansii = va_arg(lst, const char*);

        if(!ansii)
            ansii = "!";
    }
    va_end(lst);

    rs[rs.size()-1] = '\0';
    rs = _format(rs.c_str());
    printf("%s%s", rs.c_str(), txt);

    set(graphics::RESET);
}
