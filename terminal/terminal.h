#ifndef TERMINAL_H
#define TERMINAL_H

#include "config.h"
#include "codes.h"
#include <regex>
#include <string>
#include <iostream>
#include <stdarg.h>

#define log                 util::terminal::get_instance()->_print
#define action(__control__) util::terminal::get_instance()->_action(__control__)

using namespace util;
using namespace util::graphics;

namespace util {

    struct bind {
            uint8_t amt;
            const char* code;

            bind(const char* ansii, uint8_t&& val) : code(ansii), amt(val) {}

            const char* constrct() {
                if(!regex_match(code, std::regex("#[A-Z]{1}"))) {
                    throw __EXCEPTION__("invalid code for binding");
                    exit(EXIT_FAILURE);
                }
                char* tmp = (char*)&code;
                tmp[0] = amt;
                std::cout << code << "\n";
                return static_cast<const char*>(this->code);
            }
        };

    class terminal {
    private:
        ~terminal();
        terminal() = default;
    
    public:
        static terminal* get_instance();

    private:
        std::string _format(const char* ansii) const;

    public:
        void _action(const char* ansii);
        void _print(const char* txt, const char* ansii, ...) const;

    private:
        static terminal* inst;
    };
};

#endif // TERMINAL_H