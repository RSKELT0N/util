#ifndef TERMINAL_H
#define TERMINAL_H

#include "config.h"
#include "codes.h"
#include <iostream>
#include <regex>
#include <string.h>
#include <stdarg.h>

#define GRAPHIC_REGEX            std::regex("^[0-9;]+$")
#define CONTROL_REGEX            std::regex("^[a-zA-Z0-9#?=]+$")
#define BIND_REGEX               std::regex("#[A-Z]{1}")

#define log                      util::terminal::get_instance()->_print
#define action(__control__)      util::terminal::get_instance()->_action(__control__)
#define bind_(__ansii__, __amt__) util::u_bind(__ansii__, __amt__).constrct()

using namespace util;
using namespace util::graphics;

namespace util {

     struct u_bind {
            size_t      m_amt;
            const char* m_code;

            u_bind(const char* ansii, size_t&& val) : m_code(ansii), m_amt(val) {}

            const char* constrct() {
                if(!regex_match(m_code, BIND_REGEX)) {
                    exit(EXIT_FAILURE);
                }

                std::string tmp = std::to_string(m_amt) + std::string(m_code+1);
                const char* final = tmp.c_str();
                return final;
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

#endif