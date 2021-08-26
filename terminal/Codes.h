#ifndef CODES_H
#define CODES_H

namespace util {

      //ansii escape codes
     namespace codes {
         //Standard codes
        const char*  PREFIX        = "\x1b[";
        const char*  RESET         = "0m";
        const char*  SUFFIX        = "m";


         //colour codes
        const char* const  RED     = "31;";
        const char* const  GREEN   = "92;";
        const char* const  YELLOW  = "93;";
        const char* const  BLUE    = "34;";
        const char* const  MAGENTA = "95;";
        const char* const  CYAN    = "96;";
        const char* const  WHITE   = "37;";
    };
};

#endif
