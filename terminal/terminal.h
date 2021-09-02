#pragma once

#include "config.h"
#include "codes.h"
#include <regex>
#include <string>
#include <iostream>
#include <stdarg.h>

#define GRAPHIC_REGEX "^[a-zA-Z0-9;]+$"
#define CONTROL_REGEX "^[a-zA-Z0-9#?=]+$"

#define log                 util::terminal::get_instance()->_print
#define action(__control__) util::terminal::get_instance()->_action(__control__)

using namespace util;
using namespace util::graphics;

namespace util {

    struct bind {
            uint8_t     m_amt;
            const char* m_code;

            bind(const char* ansii, uint8_t&& val) : m_code(ansii), m_amt(val) {}

            const char* constrct() {
                if(!regex_match(m_code, std::regex("#[A-Z]{1}"))) {
                    throw __EXCEPTION__("invalid code for binding");
                    exit(EXIT_FAILURE);
                }
                char* tmp = (char*)&m_code;
                tmp[0] = m_amt;
                std::cout << m_code << "\n";
                return static_cast<const char*>(this->m_code);
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
        static terminal* m_inst;
    };
};