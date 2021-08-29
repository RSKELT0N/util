#ifndef TERMINAL_H
#define TERMINAL_H

#include "config.h"
#include <iostream>
#include <sstream>
#include <initializer_list>

namespace util {

    class terminal {
    private:
        ~terminal();
        terminal() = default;

    private:
        const terminal* get_instance() const;
        void print(std::initializer_list<const char*>& lst, const char* txt) const;


    private:
        mutable terminal* inst;
    };

};

#endif // TERMINAL_H