#ifndef TERMINAL_H
#define TERMINAL_H

#include "config.h"
#include "codes.h"
#include <iostream>
#include <regex>
#include <string.h>
#include <stdarg.h>

#define BIND_REGEX                    std::regex("#[A-Z]{1}")
#define GRAPHIC_REGEX                 std::regex("^[0-9;]+$")
#define CONTROL_REGEX                 std::regex("^[a-zA-Z0-9#?=]+$")

#define log                           util::terminal::get_instance()->_print
#define set                           util::terminal::get_instance()->_set
#define action(__control__)           util::terminal::get_instance()->_action(__control__)
#define bind(__ansii__, __amt__)      util::u_bind(__ansii__, __amt__).constrct()
#define set_cursor(__row__, __col__)  util::terminal::get_instance()->_set_cursor(__row__, __col__)

using namespace util;
using namespace util::graphics;

namespace util {

    struct pos {
        uint16_t x;
        uint16_t y;
    };

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
    public:
        ~terminal();

    private:
        terminal() = default;
    
    public:
        static terminal* get_instance();

    private:
        std::string _format(const char* ansii) const;

    public:
        void _get_cursor() const;
        void _set_cursor(const uint8_t& row, const uint8_t& col) const;
        void _set(const char* ansii, ...) const;
        void _action(const char* ansii);
        void _print(const char* txt, const char* ansii, ...) const;

    private:
        static std::unique_ptr<terminal> m_inst;
    };
};

#endif