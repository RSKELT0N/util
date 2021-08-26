#ifndef CODES_H
#define CODES_H

namespace util {

      //ansii escape codes
     namespace codes {
         //Standard codes
        const char*  PREFIX        = "\x1b[";
        const char*  RESET         = "0m";


         //colour codes
        const char* const  RED     = "1;31m";
        const char* const  GREEN   = "1;92m";
        const char* const  YELLOW  = "1;93m";
        const char* const  BLUE    = "1;34m";
        const char* const  MAGENTA = "1;95m";
        const char* const  CYAN    = "1;96m";
        const char* const  WHITE   = "1;37m";
    };
};

#endif
